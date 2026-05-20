#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

struct SPowerData {
    float m_Amp;
    float m_Res;
    float m_Power;
};

class CPowerInfo {
private:
    SPowerData *m_power_array; 
    int m_numElements; 
    fstream m_File;

public:
    CPowerInfo() {
        m_power_array = nullptr;
        m_numElements = 0;
    }


    ~CPowerInfo() {
        if (m_power_array != nullptr) {
            delete[] m_power_array;
        }
    }


    int getNumElements(string pFile) {
        m_File.open(pFile);
        if (!m_File.is_open()) {
            throw string("Error: File not found while counting elements!"); 
        }
        
        int count = 0;
        float temp1, temp2;

        while (m_File >> temp1 >> temp2) {
            count++;
        }
        m_File.close();
        return count;
    }


    void LoadData(string pFile, int numElements) {
        m_numElements = numElements;

        m_power_array = new SPowerData[m_numElements];

        m_File.open(pFile);
        if (!m_File.is_open()) {
            throw string("Error: File not found while loading data!"); 
        }

        cout << "\nTotal elements: " << numElements << endl;
        for (int i = 0; i < m_numElements; i++) {
            m_File >> m_power_array[i].m_Amp >> m_power_array[i].m_Res;
            
            m_power_array[i].m_Power = pow(m_power_array[i].m_Amp, 2) * m_power_array[i].m_Res;
            
            cout << m_power_array[i].m_Amp << "\t" << m_power_array[i].m_Res 
                 << "\t Calculated Power: " << m_power_array[i].m_Power << " W" << endl;
        }
        m_File.close();
    }

    void FindMinMaxPower(float &outMinPower, float &outMaxPower) {
        if (m_numElements == 0 || m_power_array == nullptr) return;


        outMinPower = m_power_array[0].m_Power;
        outMaxPower = m_power_array[0].m_Power;

        for (int i = 1; i < m_numElements; i++) {
            if (m_power_array[i].m_Power < outMinPower) {
                outMinPower = m_power_array[i].m_Power;
            }
            if (m_power_array[i].m_Power > outMaxPower) {
                outMaxPower = m_power_array[i].m_Power;
            }
        }
    }
};

int main() {
 
    try {
        CPowerInfo pw;
        
        int numElements = pw.getNumElements("AmpRes.txt"); 
        
        pw.LoadData("AmpRes.txt", numElements);
        
        float minpower, maxpower;
        pw.FindMinMaxPower(minpower, maxpower);
        
        cout << "\n-----------------------------------";
        cout << "\n The minimum power = " << minpower;
        cout << "\n The maximum power = " << maxpower;
        cout << "\n-----------------------------------" << endl;

        cout << "==> Test program executed successfully with proper Exception Handling!" << endl;
        
    } catch (string errorMsg) {
        cout << "\n[EXCEPTION CAUGHT]: " << errorMsg << endl;
    }

    return 0;
}