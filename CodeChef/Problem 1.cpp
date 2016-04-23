#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void) {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n,sx,sy,ex,ey,bx,by,ans;
		ans=0;
		scanf("%d %d %d %d %d %d %d",&n,&sx,&sy,&ex,&ey,&bx,&by);
		if(sx!=ex && sy!=ey) {
			ans=abs(sx-ex)+abs(sy-ey);
		}
		else {
	        if(sx==ex && bx==sx) {
				if(sy>ey) {
					if(by>ey && by<sy)
					    ans=abs(sy-ey)+2;
					else 
					    ans=sy-ey;
				}
				else if(ey>sy) {
					if(by<ey && by>sy)
					    ans=abs(ey-sy)+2;
					else
					    ans=ey-sy;
				}
			}
			else if(sy==ey && by==sy) {
				if(sx>ex) {
					if(bx<sx && bx>ex) 
						ans=abs(sx-ex)+2;
					else
					    ans=abs(sx-ex);
					
				    }
				else if(sx<ex) {
					if(bx<ex && bx>sx)
					    ans=abs(ex-sx)+2;
					else
					    ans=abs(ex-sx);
				}
			}
			else {
				ans=abs(sx-ex)+abs(sy-ey);
			}
		}
		printf("%d\n",ans);
	}
}
