int maxFrequency(string s)

    {

    	string temp;

    	for(int i=1;i<s.size();i++){

    	    if(s.substr(0,i)==s.substr(s.size()-i,i)){

    	       temp=s.substr(0,i);

    	       break;

    	    }

    	}

    	if(temp.size()==0)

    	    return 1;

    	

    	int ans=0;

    	

    	for(int i=0;i<s.size();i++){

    	    if(temp==s.substr(i,temp.size()))

    	           ans++;

    	}

    	

    return ans;

    	

    }
