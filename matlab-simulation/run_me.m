clear all
close all
% Robot initial position
thi = [60,60]*pi/180;
% Robot params
l=[7,7];
th_prev=thi;
%Plot workspace
% plotworkspace(l)
while 1
    
    prompt = 'Enter coordinates to go to: ';
    x=input(prompt);    
    [th,update] = performIK(x,l,th_prev);
    
    animate(th,l);
    display 'angles: '
    disp(th*(180/pi))
    if update==1     
        th_prev=th;
    else
        display('retry: ')
    end

end
   