function createVideo(name, images)   
    writerObj = VideoWriter(name);
    open(writerObj);
    for i = 1:length(images)   
            writeVideo(writerObj, images{i});
    end
    close(writerObj);
end