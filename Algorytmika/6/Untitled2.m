

n=6;

e=[1,1,1,1,1,1]';
a=[0;0;0;0;0;0]; %hanging

alphas=0.0:0.075:1;
T=100000;
m=2;
M=[0,0,0,1,1,0;0,0,0,0,0,1;0,1,0,0,0,0;1,0,0,0,0,0;0,0,0,1,0,0;1,1,1,1,1,1];
M(5,2)=mod(m,2);%removes conection between E->B
H=M;
for ii=1:n
    checker=0;
    for jj=1:n
        if(H(ii,jj)==1)
            checker=checker+1;
        end
    end
    if(checker~=0)
        H(ii,:)=H(ii,:)/checker;
    end

end
D=1/n*a*e';
Hprim=H+D;
for t=1:length(alphas)
    alpha=alphas(t);
    G=(1-alpha)*Hprim+alpha/n*e*e';
    Gt=G^T;
    ploter=1:6;
    %% PLOT

    bar(ploter',Gt(1,:),0.5);
    xlabel="state";
    ylabel="probability";
    axis([0,7,0,1]);
    xticklabels({'\Pi_A','\Pi_B','\Pi_C','\Pi_D','\Pi_E','\Pi_F'})
    grid on;


    %% GIF UTILITIES
    set(gcf,'color','w'); % set figure background to white
    drawnow;
    frame = getframe(1);
    im = frame2im(frame);
    [imind,cm] = rgb2ind(im,256);
    outfile = '2stationary.gif';


    % On the first loop, create the file. In subsequent loops, append.
    if t==1
        imwrite(imind,cm,outfile,'gif','DelayTime',0,'loopcount',inf);
    else
        imwrite(imind,cm,outfile,'gif','DelayTime',0,'writemode','append');
    end
end
