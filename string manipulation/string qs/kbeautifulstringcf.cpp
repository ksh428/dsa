#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;

	//if length not divisible by k
	if(n%k!=0){
		cout<<-1;
	}

	//otherwise
	else{
		int cnt[26];
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;i++){
            cnt[s[i]-'a']++;
        }

        //check if the string is alredy beautiful
		bool pp=1;
		for(int i=0;i<26;i++){
			if(cnt[i]%k!=0){
				pp=0;
				break;
			}
		}
		if(pp){
			cout<<s<<endl;
			return;
		}

        //now we have to make the string beautiful
        bool found=0;
        int save,i,left;
		for(i=n-1;i>=0;i--){
            int rem;
            for(int j=s[i]-'a'+1;j<26;j++){
                int place=0;
                for(int K=0;K<26;K++){
                    if(s[i]-'a'==K){
                        rem=cnt[K]-1;
                        rem=(k-(rem%k))%k;
                        place+=rem;
                    }
                    else if(j==K){
                        rem=cnt[K]+1;
                        rem=(k-(rem%k))%k;
                        place+=rem;
                    }
                    else{
                        rem=cnt[K];
                        rem=(k-(rem%k))%k;
                        place+=rem;
                    }
                }
                if(place>n-i-1){
                    //not possible
                }
                else{
                    left=((n-i-1)-place);
                    if(left%k==0){
                        found=1;
                        save=j;
                        break;
                    }
                }
            }
            if(found)break;
            cnt[s[i]-'a']--;
        }


        string ans="";

        memset(cnt,0,sizeof(cnt));

        for(int j=0;j<i;j++){
            ans+=s[j];
            cnt[s[j]-'a']++;
        }

        ans+=((char)(save+'a'));
        cnt[save]++;
        while(left--){
            ans+='a';
        }
        for(int j=0;j<26;j++){
            while(cnt[j]%k!=0){
                cnt[j]++;
                ans+=(char)(j+'a');
            }
        }
		cout<<ans;
	}

	cout<<endl;
}

//driver function
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    // t=1;
    while(t--){
        solve();
    }
    return 0;
}
