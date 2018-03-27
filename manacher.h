inline std::vector<int> manacher(char *S){
  int len=strlen(S);
  char *T=new char[len*2+1];
  memset(T,'#',sizeof T);
  for(int i=0;i<len;++i)
    T[i<<1|1]=S[i];
  std::vector<int>res=vector<int>(len*2+1,0);
  int rht=0,mir=0;
  for(int i=1;i<=len*2;++i){
    if(i>rht) res[i]=1;
    else res[i]=std::min(res[2*mir-i],rht-i);
    while(i>=res[i]&&T[i-res[i]]==T[i+res[i]]) ++res[i];
    if(i+res[i]>rht) mir=i,rht=i+res[i];
  }
  return res;
}

inline vector<int> manacher(const string &S){
	int len=S.length();
	char *T=new char[len*2+1];
	memset(T,'#',(len*2+1)*sizeof(char));
	for(int i=0;i<len;++i)
		T[i<<1|1]=S[i];
	vector<int>res=vector<int>(len*2+1,0);
	int rht=0,mir=0;
	for(int i=1;i<=len*2;++i){
		if(i>=rht) res[i]=1;
		else res[i]=min(res[2*mir-i],rht-i);
		while(i>=res[i]&&T[i-res[i]]==T[i+res[i]]) ++res[i];
		if(i+res[i]>rht) mir=i,rht=i+res[i];
	}
	return res;
}
