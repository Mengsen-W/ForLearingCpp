/*
 * @Author: Mengsen.Wang
 * @Date: 2019-12-18 19:28:06
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2019-12-18 20:13:05
 */
// 电脑组装的多态案例
#include <iostream>
#include <string>
using namespace std;

// 抽象CPU类
class CPU {
    // CPU 的计算方法
   public:
    virtual void calculate() = 0;
    virtual ~CPU() = 0;
};
CPU::~CPU() { return; }

// 抽象显卡类
class VideoCard {
    // 显卡的显示方法
   public:
    virtual void display() = 0;
    virtual ~VideoCard() = 0;
};
VideoCard::~VideoCard() { return; }

// 抽象内存类
class Memory {
    // 内存的储存方法
   public:
    virtual void storage() = 0;
    virtual ~Memory() = 0;
};
Memory::~Memory() { return; }

// 电脑类
class Computer {
   public:
    Computer(CPU* cpu, VideoCard* videoCard, Memory* memory) {
        m_cpu = cpu;
        m_videoCard = videoCard;
        m_memory = memory;
    }
    void worker() {
        m_cpu->calculate();
        m_videoCard->display();
        m_memory->storage();
    }

    ~Computer() {
        if (m_cpu != nullptr) {
            delete m_cpu;
            m_cpu = nullptr;
        }
        if (m_videoCard != nullptr) {
            delete m_videoCard;
            m_videoCard = nullptr;
        }
        if (m_memory != nullptr) {
            delete m_memory;
            m_memory = nullptr;
        }
    }

   private:
    CPU* m_cpu;              // cpu的零件指针
    VideoCard* m_videoCard;  // 显卡的零件指针
    Memory* m_memory;        // 内存的零件指针
};

// Intel 厂商
class IntelCpu : public CPU {
    void calculate() { cout << "IntelCpu" << endl; }
};

class IntelVideoCard : public VideoCard {
    void display() { cout << "IntelDisplay" << endl; }
};

class IntelMemory : public Memory {
    void storage() { cout << "IntelStorage" << endl; }
};
// AMD 厂商
class AMDCpu : public CPU {
    void calculate() { cout << "AMDCpu" << endl; }
};

class AMDDisplay : public VideoCard {
    void display() { cout << "AMDDisplay" << endl; }
};

class AMDMemory : public Memory {
    void storage() { cout << "AMDStorage" << endl; }
};

void test01() {
    // 第一个电脑
    CPU* intelcpu = new IntelCpu;
    VideoCard* intelvideocard = new IntelVideoCard;
    Memory* intelmemory = new IntelMemory;

    Computer* computer1 = new Computer(intelcpu, intelvideocard, intelmemory);
    computer1->worker();
    delete computer1;

    //第二个电脑
    Computer* computer2 =
        new Computer(new AMDCpu, new AMDDisplay, new AMDMemory);
    computer2->worker();
    delete computer2;

    //第三台
    Computer* computer3 =
        new Computer(new IntelCpu, new AMDDisplay, new IntelMemory);
    computer3->worker();
    delete computer3;
}

int main(int argc, char* argv[]) {
    test01();
    return 0;
}