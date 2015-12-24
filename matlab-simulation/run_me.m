
% Robot initial position
thi = [60,60]*pi/180;
% Robot params
l=[7,7];
th_prev=thi;
while 1
    
    %GET USER COORDINATE INPUTS
    input = [0;14];
    
    [th,update] = performIK(input,l,th_prev);
    animate(th,l);
    if update==1     
        th_prev=th;
    else
        display('retry: ')
    end

end
   