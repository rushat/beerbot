function animate(th,l)

x1 = l(1)*cos(th(1));
y1 = l(1)*sin(th(1));
x2 = l(1)*cos(th(1)) + l(2)*cos(th(1)+th(2));
y2 = l(1)*sin(th(1)) + l(2)*sin(th(1)+th(2));

figure(1)
hold on
axis([-15,15,-15,15])
plot([0,x1,x2], [0,y1,y2], 'r', 'LineWidth',3, 'MarkerSize', 4);

end