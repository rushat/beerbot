function [th,update] = performIK(input,l,th_prev)

x=input(1);
y=input(2);
if (x^2 + y^2)^(1/2) <=2*l(1)

    th2 = 2*acos(((x.^2 + y.^2)^(1/2))/(2*l(1)));
    th1 = atan2(y,x) - (th2/2);
    if(th2>=0 && th2<=pi && th1>=0 && th1<=pi)
     th=[th1;th2];
     update=1;
    else
        th=th_prev;
        update=0;
    end
else
  th=th_prev;
  update=0;

end

end
