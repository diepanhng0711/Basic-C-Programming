// hàm tìm node thế mạng
void NodeTheMang(TREE &X, TREE &Y) // NODE Y là node thế mạng cho node cần xóa - node này sẽ đảm nhận nhiệm vụ tìm ra node trái nhất(TÌM NODE TRÁI NHẤT CÂY CON PHẢI) hoặc phải nhất(TÌM NODE PHẢI NHẤT CỦA CÂY CON TRÁI)
{
    // CÁCH 1: TÌM NODE TRÁI NHẤT CỦA CÂY CON PHẢI
    // duyệt sang bên trái nhất
    if (Y->pLeft != NULL)
    {
        NodeTheMang(X, Y->pLeft);// tìm ra node trái nhất ?
    }
    else // tìm ra được node trái nhất rồi nek..
    {
        X->data = Y->data; // cập nhật cái data của node cần xóa chính là data của node thế mạng
        X = Y; // cho node X(là node mà chúng ta sẽ đi xóa sau này) trỏ đến node thế mạng ==> ra khỏi hàm thì ta sẽ xóa node X
        Y = Y->pRight; // bản chất chỗ này chính là cập nhật lại mối liên kết cho node cha của node thế mạng(mà chúng ta sẽ xóa) với node con của node thế mạng  
    }
 
    /* CÁCH 2: TÌM NODE PHẢI NHẤT CỦA CÂY CON TRÁI
     duyệt sang bên phải
     if (Y->pRight != NULL)
    {
        DiTimNodeTheMang(X, Y->pRight);// tìm ra node phải nhất ?
    }
    else // tìm ra được node phải nhất rồi nek..
    {
        X->data = Y->data; // cập nhật cái data của node cần xóa chính là data của node thế mạng
        X = Y; // cho node X(là node mà chúng ta sẽ đi xóa sau này) trỏ đến node thế mạng ==> ra khỏi hàm thì ta sẽ xóa node X
        Y = Y->pLeft; // bản chất chỗ này chính là cập nhật lại mối liên kết cho node cha của node thế mạng(mà chúng ta sẽ xóa) với node con của node thế mạng   
    } */
}
 
// hàm xóa 1 cái node bất kì trong cây nhị phân tìm kiếm
void XoaNode(TREE &t, int data) // data chính là giá trị của cái node cần xóa
{
    // nếu như cây đang rỗng
    if (t == NULL)
    {
        return; // kết thúc hàm
    }
    else
    {
        // nếu như data nhỏ hơn node gốc
        if (data < t->data)
        {
            XoaNode(t->pLeft, data); // duyệt sang nhánh trái của cây 
        }
        else if (data > t->data)
        {
            XoaNode(t->pRight, data); // duyệt sang nhánh phải của cây 
        }
        else // data == t->data - đã tìm ra cái node cần xóa
        {
            NODE *X = t; // node X là node thế mạng - tí nữa chúng ta sẽ xóa nó
            // nếu như nhánh trái bằng NULL <=> đây là cây có 1 con chính là con phải
            if (t->pLeft == NULL)
            {
                // duyệt sang phải của cái node cần xóa để cập nhật mối liên kết giữa node 
                // cha của node cần xóa với node con của node cần xóa
                t = t->pRight; 
            }
            else if (t->pRight == NULL)
            {
                // duyệt sang trái của cái node cần xóa để cập nhật mối liên kết giữa node 
                // cha của node cần xóa với node con của node cần xóa
                t = t->pLeft;
            }
            else // node cần xóa là node có 2 con
            {
                // CÁCH 1: Tìm node trái nhất của cây con phải(cây con phải của cái node cần xóa)
                NodeTheMang(X, t->pRight);
                // CÁCH 2: Tìm node phải nhất của cây con trái(cây con trái của cái node cần xóa)
                //DiTimNodeTheMang(X, t->pLeft);
            }
            delete X; // xóa node cần xóa
        }
    }
}