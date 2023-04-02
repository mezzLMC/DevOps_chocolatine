echo "Start!"
ls stacks | while read -r file;
    do 
    content=`cat stacks/$file`;
    echo $file
    ./push_swap $content;
done
echo "End!"