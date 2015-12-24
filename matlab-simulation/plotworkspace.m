function [] = plotworkspace(l)
l=l(1);
for i= 1:5:180
    th1 = i-1;
    for j= 1:5:181
        th2 = j-91;
    x = l*cosd(th1)+l*cosd(th1+th2);
    y = l*sind(th1)+l*sind(th1+th2);
    figure(1)
    plot(x,y,'*b')
    axis([-15,15,-15,15])
    hold on
    end
end
