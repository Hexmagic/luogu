#include <opencv2/opencv.hpp>
#include <vector>
#include <math.h>
#include <iostream>
#include <fstream>
#include <flann/flann.hpp>
using namespace std; 
using namespace flann;


auto readTxt(const char* filename){
    ifstream in(filename);
    string x,y,z;
    string fname = filename;
    bool is_time = fname.find("time")!=string::npos;
    vector<cv::Point3d> ans;
    while(!in.eof()){
        if(is_time){
            in>>x;
            ans.push_back(cv::Point3d(stod(x),0.0,0.0));
        }else{
            in>>x>>y>>z;
            ans.push_back(cv::Point3d(stod(x),stod(y),stod(z)));
        }
    }
    return ans;
}



int main(int args,char**argv){
    string pof_name = "pof.txt";
    string point_name = "point.txt";
    string output = "output.txt";
    vector<cv::Point3d> pof= readTxt(pof_name.c_str());   
    auto base = pof[0];
    for(int i=0;i<pof.size();i++){
        pof[i]-=base;
    }
    int M = pof.size();
    double pof_arr[M][3];
    for(int i=0;i<M;i++){
        pof_arr[i][0]=pof[i].x;
        pof_arr[i][1]=pof[i].y;
        pof_arr[i][2]=pof[i].z;
    }
    auto points = readTxt(point_name.c_str()); 
    
    for(int i=0;i<points.size();i++){
        points[i]-=base;
    }
    points.pop_back();
    
    Matrix<double> dataset((double *)pof_arr,pof.size(),size_t(3));
    flann::KDTreeSingleIndex<L2<double>> index(dataset,flann::KDTreeIndexParams(128));
    Matrix<double> query((double*)points.data(),points.size(),size_t(3));
    index.buildIndex();
    int nn=1;
    Matrix<int> indexs(new int[query.rows*nn],query.rows,nn);
    Matrix<double> dists(new double[query.rows*nn],query.rows,nn);

    
    index.knnSearch(query,indexs,dists,nn,flann::SearchParams(256));
    vector<int> ind;
    ind.assign(indexs.ptr(),indexs.ptr()+query.rows);
    for(int i=0;i<query.rows;i++){
        cout<<*indexs[i]<<":"<<*dists[i]<<endl;
        cout<<cv::norm(points[i]-pof[*indexs[i]])<<endl;
    }
    return 0;
}