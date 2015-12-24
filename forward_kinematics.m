
l=7;
for i= 1:1:180
    th1 = i-1;
    for j= 1:1:181
        th2 = j-91;
    x = l*cosd(th1)+l*cosd(th1+th2);
    y = l*sind(th1)+l*sind(th1+th2);
    figure(1)
    plot(x,y,'*r')
    axis([-15,15,-15,15])
    hold on
    end
end

