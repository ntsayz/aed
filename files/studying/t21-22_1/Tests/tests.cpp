#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Bookstore.h"
#include "Book.h"
#include "Warehouse.h"
#include "Packer.h"
#include "Order.h"

using testing::Eq;

TEST(aed2122_ci1, alinea_a) {
    cout << endl << "Testing 'sort'" << endl;
    Warehouse w;

    w.sortPackers();
    list<Packer> p = w.getPackers();
    EXPECT_EQ(0, p.size());
    p.clear();

    Packer p1(1111, "A");
    p1.addOrder(new Order("o1", "dt1"));

    Packer p2(1112, "B");
    p2.addOrder(new Order("o2", "dt2"));
    p2.addOrder(new Order("o3", "dt3"));
    p2.addOrder(new Order("o4", "dt1"));

    Packer p3(1113, "C");
    p3.addOrder(new Order("o5", "dt1"));

    Packer p4(1114, "D");
    p4.addOrder(new Order("o6", "dt2"));
    p4.addOrder(new Order("o7", "dt2"));
    p4.addOrder(new Order("o8", "dt1"));
    p4.addOrder(new Order("o9", "dt1"));
    p4.addOrder(new Order("o10", "dt3"));
    p4.addOrder(new Order("o11", "dt5"));
    p4.addOrder(new Order("o12", "dt1"));

    Packer p5(1115, "E");
    p5.addOrder(new Order("o13", "dt1"));
    p5.addOrder(new Order("o14", "dt2"));
    p5.addOrder(new Order("o15", "dt3"));
    p5.addOrder(new Order("o16", "dt3"));
    p5.addOrder(new Order("o17", "dt1"));

    Packer p6(9999, "A");
    p6.addOrder(new Order("o18", "dt1"));

    Packer p7(1116, "B");
    p7.addOrder(new Order("o19", "dt1"));

    w.addPacker(p1);
    w.addPacker(p2);
    w.addPacker(p3);
    w.addPacker(p4);
    w.addPacker(p5);
    w.addPacker(p6);
    w.addPacker(p7);

    w.sortPackers();
    p = w.getPackers();
    EXPECT_EQ(7, p.size());

    if (p.size() == 7) {
        EXPECT_EQ("D", p.front().getNamePacker());
        EXPECT_EQ(7, p.front().getOrderQueue().size());
        p.pop_front();
        EXPECT_EQ("E", p.front().getNamePacker());
        EXPECT_EQ(5, p.front().getOrderQueue().size());
        p.pop_front();
        EXPECT_EQ("B", p.front().getNamePacker());
        EXPECT_EQ(3, p.front().getOrderQueue().size());
        p.pop_front();
        EXPECT_EQ("A", p.front().getNamePacker());
        EXPECT_EQ(1111, p.front().getIdPacker());
        EXPECT_EQ(1, p.front().getOrderQueue().size());
        p.pop_front();
        EXPECT_EQ("A", p.front().getNamePacker());
        EXPECT_EQ(9999, p.front().getIdPacker());
        EXPECT_EQ(1, p.front().getOrderQueue().size());
        p.pop_front();
        EXPECT_EQ("B", p.front().getNamePacker());
        EXPECT_EQ(1, p.front().getOrderQueue().size());
        p.pop_front();
        EXPECT_EQ("C", p.front().getNamePacker());
        EXPECT_EQ(1, p.front().getOrderQueue().size());
        p.pop_front();
    }
}


TEST(aed2122_ci1, alinea_b) {
    cout << endl << "Testing 'removePackers'" << endl;
    Warehouse w1;

    Packer p11(1111, "p11");
    p11.addOrder(new Order("o11", "dt1"));
    p11.addOrder(new Order("o12", "dt2"));
    p11.addOrder(new Order("o13", "dt3"));

    Packer p12(1112, "p12");
    p12.addOrder(new Order("o14", "dt1"));

    Packer p13(1113, "p13");
    p13.addOrder(new Order("o15", "dt1"));
    p13.addOrder(new Order("o16", "dt2"));
    p13.addOrder(new Order("o17", "dt3"));
    p13.addOrder(new Order("o18", "dt1"));

    w1.addPacker(p11);
    w1.addPacker(p12);
    w1.addPacker(p13);

    EXPECT_EQ(1, w1.removePackers(3));

    list<Packer> p1 = w1.getPackers();
    EXPECT_EQ(2, p1.size());
    if (p1.size() == 2) {
        EXPECT_EQ("p11", p1.front().getNamePacker());
        EXPECT_EQ(1111, p1.front().getIdPacker());
        p1.pop_front();
        EXPECT_EQ("p13", p1.front().getNamePacker());
        EXPECT_EQ(1113, p1.front().getIdPacker());
    }
    p1.clear();

    Warehouse w2;

    Packer p21(2111, "p21");
    p21.addOrder(new Order("o21", "dt1"));

    Packer p22(2112, "p22");
    p22.addOrder(new Order("o22", "dt2"));
    p22.addOrder(new Order("o23", "dt3"));
    p22.addOrder(new Order("o24", "dt1"));

    Packer p23(2113, "p23");
    p23.addOrder(new Order("o25", "dt1"));
    p23.addOrder(new Order("o26", "dt2"));

    Packer p24(2114, "p24");
    p24.addOrder(new Order("o27", "dt1"));
    p24.addOrder(new Order("o28", "dt2"));
    p24.addOrder(new Order("o29", "dt4"));
    p24.addOrder(new Order("o210", "dt2"));
    p24.addOrder(new Order("o211", "dt1"));

    w2.addPacker(p21);
    w2.addPacker(p22);
    w2.addPacker(p23);
    w2.addPacker(p24);

    EXPECT_EQ(3, w2.removePackers(3));

    list<Packer> p2 = w2.getPackers();
    EXPECT_EQ(2, p2.size());
    if(p2.size() == 2) {
        EXPECT_EQ("p22", p2.front().getNamePacker());
        EXPECT_EQ(2112, p2.front().getIdPacker());
        p2.pop_front();
        EXPECT_EQ(1, p2.size());
        EXPECT_EQ("p24", p2.front().getNamePacker());
        EXPECT_EQ(2114, p2.front().getIdPacker());
    }
    p2.clear();

    Warehouse w3;

    Packer p31(3111, "p31");
    p31.addOrder(new Order("o31", "dt1"));

    Packer p32(3112, "p32");
    p32.addOrder(new Order("o32", "dt2"));
    p32.addOrder(new Order("o33", "dt3"));

    Packer p33(3113, "p33");
    p33.addOrder(new Order("o34", "dt1"));
    p33.addOrder(new Order("o35", "dt1"));
    p33.addOrder(new Order("o36", "dt2"));
    p33.addOrder(new Order("o37", "dt4"));

    Packer p34(3114, "p34");
    p34.addOrder(new Order("o38", "dt2"));
    p34.addOrder(new Order("o39", "dt1"));
    p34.addOrder(new Order("o310", "dt1"));
    p34.addOrder(new Order("o311", "dt2"));

    w3.addPacker(p31);
    w3.addPacker(p32);
    w3.addPacker(p33);
    w3.addPacker(p34);

    EXPECT_EQ(3, w3.removePackers(3));

    list<Packer> p3 = w3.getPackers();
    EXPECT_EQ(2, p3.size());
    if (p3.size() == 2) {
        EXPECT_EQ("p33", p3.front().getNamePacker());
        EXPECT_EQ(3113, p3.front().getIdPacker());
        p3.pop_front();
        EXPECT_EQ(1, p3.size());
        EXPECT_EQ("p34", p3.front().getNamePacker());
        EXPECT_EQ(3114, p3.front().getIdPacker());
    }
    p3.clear();
}


TEST(aed2122_ci1, alinea_c) {
    cout << endl << "Testing 'addPacker'" << endl;
    Warehouse w1;

    Packer pA(1111, "pA");
    pA.addOrder(new Order("o1", "dt1"));
    w1.addPacker(pA);

    w1.addPacker(9999, "pX");

    list<Packer> p = w1.getPackers();
    EXPECT_EQ(2, p.size());
    if (p.size() == 2) {
        Packer pY = p.back();
        EXPECT_EQ(9999, pY.getIdPacker());
        EXPECT_EQ(0, pY.getOrderQueue().size());
        Packer pZ = p.front();
        EXPECT_EQ(1111, pZ.getIdPacker());
        EXPECT_EQ(1, pZ.getOrderQueue().size());
    }
    p.clear();

    Warehouse w2;

    Packer p1(1111, "p1");
    p1.addOrder(new Order("o1", "dt1"));

    Packer p2(1112, "p2");
    p2.addOrder(new Order("o2", "dt1"));
    p2.addOrder(new Order("o3", "dt2"));
    p2.addOrder(new Order("o4", "dt4"));
    p2.addOrder(new Order("o5", "dt2"));

    Packer p3(1113, "p3");
    p3.addOrder(new Order("o6", "dt1"));
    p3.addOrder(new Order("o7", "dt2"));
    p3.addOrder(new Order("o8", "dt1"));

    w2.addPacker(p1);
    w2.addPacker(p2);
    w2.addPacker(p3);

    w2.addPacker(9999, "p4");
    p = w2.getPackers();
    EXPECT_EQ(4, p.size());

    if (p.size() == 4) {
        Packer p4 = p.back();
        EXPECT_EQ(9999, p4.getIdPacker());
        queue<Order *> p4oq = p4.getOrderQueue();
        EXPECT_EQ(2, p4oq.size());
        if (p4oq.size() == 2) {
            EXPECT_EQ("o2", p4oq.front()->getOrderNumber());
            p4oq.pop();
            EXPECT_EQ("o6", p4oq.front()->getOrderNumber());
        }

        EXPECT_EQ(1, p.front().getOrderQueue().size());
        EXPECT_EQ("p1", p.front().getNamePacker());
        if (p.front().getOrderQueue().size() == 1)
            EXPECT_EQ("o1", p.front().getOrderQueue().front()->getOrderNumber());
        p.pop_front();

        EXPECT_EQ(3, p.front().getOrderQueue().size());
        EXPECT_EQ("p2", p.front().getNamePacker());
        if (p.front().getOrderQueue().size() == 3) {
            EXPECT_EQ("o3", p.front().getOrderQueue().front()->getOrderNumber());
            EXPECT_EQ("o5", p.front().getOrderQueue().back()->getOrderNumber());
        }
        p.pop_front();

        EXPECT_EQ(2, p.front().getOrderQueue().size());
        EXPECT_EQ("p3", p.front().getNamePacker());
        if (p.front().getOrderQueue().size() == 2) {
            EXPECT_EQ("o7", p.front().getOrderQueue().front()->getOrderNumber());
            EXPECT_EQ("o8", p.front().getOrderQueue().back()->getOrderNumber());
        }
        p.pop_front();

        EXPECT_EQ(2, p.front().getOrderQueue().size());
        EXPECT_EQ("p4", p.front().getNamePacker());
        EXPECT_EQ(1, p.size());
    }
}


TEST(aed2122_ci1, alinea_d) {
    cout << endl << "Testing 'addToShorterQueue'" << endl;
    Warehouse w1;

    EXPECT_EQ(false, w1.addToShorterQueue(new Order("O", "dt1")));
    EXPECT_EQ(0, w1.getPackers().size());

    Warehouse w2;

    Packer p1(1111, "p1");
    p1.addOrder(new Order("o1", "dt1"));
    p1.addOrder(new Order("o2", "dt2"));
    p1.addOrder(new Order("o3", "dt4"));
    p1.addOrder(new Order("o4", "dt1"));

    Packer p2(1112, "p2");

    Packer p3(1111, "p1");
    p3.addOrder(new Order("o5", "dt1"));
    p3.addOrder(new Order("o6", "dt3"));

    Packer p4(1114, "p4");
    p4.addOrder(new Order("o7", "dt1"));

    w2.addPacker(p1);
    w2.addPacker(p2);
    w2.addPacker(p3);
    w2.addPacker(p4);

    EXPECT_EQ(true, w2.addToShorterQueue(new Order("o8", "dt3")));
    list<Packer> p = w2.getPackers();
    EXPECT_EQ(4, p.size());
    if (p.size() == 4) {
        queue<Order *> oq1 = p.front().getOrderQueue();
        EXPECT_EQ(4, oq1.size());
        p.pop_front();
        queue<Order *> oq2 = p.front().getOrderQueue();
        EXPECT_EQ(1, oq2.size());
        if (oq2.size() == 1)
            EXPECT_EQ("o8", oq2.back()->getOrderNumber());
    }
    p.clear();

    Warehouse w3;

    Packer p11(1111, "p1");
    p11.addOrder(new Order("o1", "dt1"));
    p11.addOrder(new Order("o2", "dt2"));
    p11.addOrder(new Order("o3", "dt4"));
    p11.addOrder(new Order("o4", "dt1"));

    Packer p12(1112, "p2");
    p12.addOrder(new Order("o8", "dt3"));

    Packer p13(1111, "p1");
    p13.addOrder(new Order("o5", "dt1"));
    p13.addOrder(new Order("o6", "dt3"));

    Packer p14(1114, "p4");
    p14.addOrder(new Order("o7", "dt1"));

    w3.addPacker(p11);
    w3.addPacker(p12);
    w3.addPacker(p13);
    w3.addPacker(p14);

    EXPECT_EQ(true, w3.addToShorterQueue(new Order("o9", "dt1")));
    p = w3.getPackers();
    EXPECT_EQ(4, p.size());
    if (p.size() == 4) {
        queue<Order *> oq3 = p.front().getOrderQueue();
        EXPECT_EQ(4, oq3.size());
        p.pop_front();
        oq3 = p.front().getOrderQueue();
        EXPECT_EQ(2, oq3.size());
        if (oq3.size() == 2) {
            EXPECT_EQ("o9", oq3.back()->getOrderNumber());
            EXPECT_EQ("o8", oq3.front()->getOrderNumber());
        }
        p.pop_front();
        oq3 = p.front().getOrderQueue();
        EXPECT_EQ(2, oq3.size());
        p.pop_front();
        oq3 = p.front().getOrderQueue();
        EXPECT_EQ(1, oq3.size());
    }
}


TEST(aed2122_ci1, alinea_e) {
    cout << endl << "Testing 'orderByDeliveryType'" << endl;
    Warehouse w1;
    list<stack<Order *> > o;

    stack<Order *> so1;
    so1.push(new Order("o1", "dt1"));
    so1.push(new Order("o2", "dt1"));
    so1.push(new Order("o3", "dt1"));
    so1.push(new Order("o4", "dt1"));
    o.push_back(so1);

    stack<Order *> so2;
    so2.push(new Order("o5", "dt2"));
    o.push_back(so2);
    w1.setOrders(o);

    EXPECT_EQ(4, w1.getOrders().front().size());
    unsigned n = w1.processOrderByDeliveryType("dt1", 3);
    EXPECT_EQ(3, n);
    o.clear();

    o = w1.getOrders();
    EXPECT_EQ(2, o.size());
    if (o.size() == 2) {
        EXPECT_EQ(1, o.front().size());
        EXPECT_EQ("o1", o.front().top()->getOrderNumber());
        o.pop_front();
        EXPECT_EQ(1, o.front().size());
        EXPECT_EQ("o5", o.front().top()->getOrderNumber());
    }

    Warehouse w2;

    o.clear();
    stack<Order *> so3;
    so3.push(new Order("o1", "dt1"));
    o.push_back(so3);

    stack<Order *> so4;
    so4.push(new Order("o2", "dt2"));
    so4.push(new Order("o3", "dt2"));
    so4.push(new Order("o4", "dt2"));
    so4.push(new Order("o5", "dt2"));
    o.push_back(so4);

    stack<Order *> so5;
    so5.push(new Order("o6", "dt3"));
    o.push_back(so5);

    stack<Order *> so6;
    so6.push(new Order("o7", "dt4"));
    o.push_back(so6);

    w2.setOrders(o);

    n = w2.processOrderByDeliveryType("dt2", 8);
    EXPECT_EQ(4, n);

    o.clear();
    o = w2.getOrders();
    EXPECT_EQ(3, o.size());
    if (o.size() == 3) {
        EXPECT_EQ(1, o.front().size());
        if (o.front().size() == 1)
            EXPECT_EQ("o1", o.front().top()->getOrderNumber());
        o.pop_front();
        EXPECT_EQ(1, o.front().size());
        if (o.front().size() == 1)
            EXPECT_EQ("o6", o.front().top()->getOrderNumber());
        o.pop_front();
        EXPECT_EQ(1, o.front().size());
        if (o.front().size() == 1)
            EXPECT_EQ("o7", o.front().top()->getOrderNumber());
    }
}

TEST(aed2122_ci1, alinea_f) {
    cout << endl << "Testing 'getBooksBy'" << endl;
    vector<Book *> books;
    books.push_back(new Book("a1", "t11", 2020));
    books.push_back(new Book("a1", "t12", 1985));
    books.push_back(new Book("a2", "t21", 2012));
    books.push_back(new Book("a2", "t22", 2004));
    books.push_back(new Book("a3", "t31", 1997));
    books.push_back(new Book("a3", "t32", 2016));
    books.push_back(new Book("a4", "t41", 2021));
    books.push_back(new Book("a4", "t42", 2001));
    books.push_back(new Book("a5", "t51", 1965));
    books.push_back(new Book("a6", "t61", 2021));
    books.push_back(new Book("a7", "t71", 1930));
    books.push_back(new Book("a7", "t72", 1930));
    books.push_back(new Book("a7", "t73", 1930));

    Bookstore bs;
    bs.generateCatalog(books);

    BST<BookCatalogItem> bookBST = bs.getCatalog();
    BookCatalogItem bookItem = bookBST.findMin(); // por Ano (decr) > titulo (alfab)
    EXPECT_EQ("a4", bookItem.getAuthor());
    EXPECT_EQ("t41", bookItem.getTitle());
    EXPECT_EQ(2021, bookItem.getYear());

    vector<Book *> ba = bs.getBooksBy("a5");
    EXPECT_EQ(1, ba.size());
    if (ba.size() == 1) {
        EXPECT_EQ("t51", ba.at(0)->getTitle());
    }

    ba.clear();
    ba = bs.getBooksBy("a3");
    EXPECT_EQ(2, ba.size());
    if (ba.size() == 2) {
        EXPECT_EQ(2016, ba.at(0)->getYear());
        EXPECT_EQ(1997, ba.at(1)->getYear());
    }

    ba.clear();
    ba = bs.getBooksBy("a3");
    EXPECT_EQ(2, ba.size());
    if (ba.size() == 2) {
        EXPECT_EQ(2016, ba.at(0)->getYear());
        EXPECT_EQ(1997, ba.at(1)->getYear());
    }

    ba.clear();
    ba = bs.getBooksBy("a7");
    EXPECT_EQ(3, ba.size());
    if (ba.size() == 3) {
        EXPECT_EQ(1930, ba.at(0)->getYear());
        EXPECT_EQ(1930, ba.at(1)->getYear());
        EXPECT_EQ("t71", ba.at(0)->getTitle());
        EXPECT_EQ("t72", ba.at(1)->getTitle());
        EXPECT_EQ("t73", ba.at(2)->getTitle());
    }

    ba.clear();
    ba = bs.getBooksBy("ax");
    EXPECT_EQ(0, ba.size());
}

TEST(aed2122_ci1, alinea_g) {
    cout << endl << "Testing 'getBooksBetween'" << endl;
    vector<Book *> books;
    books.push_back(new Book("a1", "t11", 2020));
    books.push_back(new Book("a1", "t12", 1985)); //
    books.push_back(new Book("a2", "t21", 2012));
    books.push_back(new Book("a2", "t22", 2004));
    books.push_back(new Book("a3", "t31", 1997)); //
    books.push_back(new Book("a3", "t32", 2016));
    books.push_back(new Book("a4", "t41", 2021));
    books.push_back(new Book("a4", "t42", 2001));
    books.push_back(new Book("a4", "t43", 2021));
    books.push_back(new Book("a5", "t51", 1965)); //
    books.push_back(new Book("a6", "t61", 2021));

    Bookstore bs;
    bs.generateCatalog(books);

    vector<Book *> by = bs.getBooksBetween(2010, 2021);

    EXPECT_EQ(6, by.size());
    if (by.size() == 6) {
        EXPECT_EQ("t41", by.at(0)->getTitle());
        EXPECT_EQ("a4", by.at(0)->getAuthor());
        EXPECT_EQ(2021, by.at(0)->getYear());

        EXPECT_EQ("t43", by.at(1)->getTitle());
        EXPECT_EQ("a4", by.at(1)->getAuthor());
        EXPECT_EQ(2021, by.at(1)->getYear());

        EXPECT_EQ("t61", by.at(2)->getTitle());
        EXPECT_EQ("a6", by.at(2)->getAuthor());
        EXPECT_EQ(2021, by.at(2)->getYear());

        EXPECT_EQ("t11", by.at(3)->getTitle());
        EXPECT_EQ("a1", by.at(3)->getAuthor());
        EXPECT_EQ(2020, by.at(3)->getYear());

        EXPECT_EQ("t32", by.at(4)->getTitle());
        EXPECT_EQ("a3", by.at(4)->getAuthor());
        EXPECT_EQ(2016, by.at(4)->getYear());

        EXPECT_EQ("t21", by.at(5)->getTitle());
        EXPECT_EQ("a2", by.at(5)->getAuthor());
        EXPECT_EQ(2012, by.at(5)->getYear());
    }

    by.clear();
    by = bs.getBooksBetween(1950, 1999);

    EXPECT_EQ(3, by.size());
    if (by.size() == 3) {
        EXPECT_EQ("t31", by.at(0)->getTitle());
        EXPECT_EQ("a3", by.at(0)->getAuthor());
        EXPECT_EQ(1997, by.at(0)->getYear());

        EXPECT_EQ("t12", by.at(1)->getTitle());
        EXPECT_EQ("a1", by.at(1)->getAuthor());
        EXPECT_EQ(1985, by.at(1)->getYear());

        EXPECT_EQ("t51", by.at(2)->getTitle());
        EXPECT_EQ("a5", by.at(2)->getAuthor());
        EXPECT_EQ(1965, by.at(2)->getYear());
    }

    by.clear();
    by = bs.getBooksBetween(2005, 2010);
    EXPECT_EQ(0, by.size());
}
