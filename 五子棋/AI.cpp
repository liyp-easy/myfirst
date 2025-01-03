#include "AI.h"

void AI::init(Chess* chess)
{
	this->chess = chess;
    int size = chess->getgradesize();
    for (int i = 0; i < size; i++) {
        vector<int> row;
        for (int j = 0; j < size; j++) {
            row.push_back(0);
        }
        scoreMap.push_back(row);
    }
}

void AI::go()
{
    Chesspos pos = think();
    Sleep(1000); //��װ˼��
    chess->chessdown(&pos, chess_white);

}

void AI::calculateScore()
{
    // ͳ����һ��ߵ������ɵ���
    int personNum = 0;  // ��������ӵĸ���
    int botNum = 0;     // AI�����ӵĸ���
    int emptyNum = 0;   // ������հ�λ�ĸ���

    // �����������
    for (int i = 0; i < scoreMap.size(); i++) {
        for (int j = 0; j < scoreMap[i].size(); j++) {
            scoreMap[i][j] = 0;
        }
    }

    int size = chess->getgradesize();
    for (int row = 0; row < size; row++)
        for (int col = 0; col < size; col++)
        {
            // �հ׵����
            if (chess->getchessdata(row, col) == 0) {
                // ����
                for (int y = -1; y <= 0; y++) {
                    for (int x = -1; x <= 1; x++)
                    {
                        // ����
                        personNum = 0;
                        botNum = 0;
                        emptyNum = 0;

                        // ԭ���겻��
                        if (!(y == 0 && x == 0) && !(y==0 && x!=1))
                        {
                            // ÿ����������4����
                            // �Ժ������֣�������������
                            for (int i = 1; i <= 4; i++)
                            {
                                int curRow = row + i * y;
                                int curCol = col + i * x;
                                if (curRow >= 0 && curRow < size &&
                                    curCol >= 0 && curCol < size &&
                                    chess->getchessdata(curRow, curCol) == 1) // ������ҵ���
                                {
                                    personNum++;
                                }
                                else if (curRow >= 0 && curRow < size &&
                                    curCol >= 0 && curCol < size &&
                                    chess->getchessdata(curRow, curCol) == 0) // �հ�λ
                                {
                                    emptyNum++;
                                    break;
                                }
                                else            // ���߽�
                                    break;
                            }

                            for (int i = 1; i <= 4; i++)
                            {
                                int curRow = row - i * y;
                                int curCol = col - i * x;
                                if (curRow >= 0 && curRow < size &&
                                    curCol >= 0 && curCol < size &&
                                    chess->getchessdata(curRow, curCol) == 1) // ������ҵ���
                                {
                                    personNum++;
                                }
                                else if (curRow >= 0 && curRow < size &&
                                    curCol >= 0 && curCol < size &&
                                    chess->getchessdata(curRow, curCol) == 0) // �հ�λ
                                {
                                    emptyNum++;
                                    break;
                                }
                                else            // ���߽�
                                    break;
                            }

                            if (personNum == 1)                      // ɱ��
                                scoreMap[row][col] += 10;
                            else if (personNum == 2)                 // ɱ��
                            {
                                if (emptyNum == 1)
                                    scoreMap[row][col] += 30;
                                else if (emptyNum == 2)
                                    scoreMap[row][col] += 40;
                            }
                            else if (personNum == 3)                 // ɱ��
                            {
                                // �����λ��һ�������ȼ���һ��
                                if (emptyNum == 1)
                                    scoreMap[row][col] += 60;
                                else if (emptyNum == 2)
                                    scoreMap[row][col] += 200;
                            }
                            else if (personNum == 4)                 // ɱ��
                                scoreMap[row][col] += 20000;

                            // ����һ�����
                            emptyNum = 0;

                            // �԰�������
                            for (int i = 1; i <= 4; i++)
                            {
                                int curRow = row + i * y;
                                int curCol = col + i * x;
                                if (curRow > 0 && curRow < size &&
                                    curCol > 0 && curCol < size &&
                                    chess->getchessdata(curRow, curCol) == -1) // ��ҵ���
                                {
                                    botNum++;
                                }
                                else if (curRow > 0 && curRow < size &&
                                    curCol > 0 && curCol < size &&
                                    chess->getchessdata(curRow, curCol) == 0) // �հ�λ
                                {
                                    emptyNum++;
                                    break;
                                }
                                else            // ���߽�
                                    break;
                            }

                            for (int i = 1; i <= 4; i++)
                            {
                                int curRow = row - i * y;
                                int curCol = col - i * x;
                                if (curRow > 0 && curRow < size &&
                                    curCol > 0 && curCol < size &&
                                    chess->getchessdata(curRow, curCol) == -1) // ��ҵ���
                                {
                                    botNum++;
                                }
                                else if (curRow > 0 && curRow < size &&
                                    curCol > 0 && curCol < size &&
                                    chess->getchessdata(curRow, curCol) == 0) // �հ�λ
                                {
                                    emptyNum++;
                                    break;
                                }
                                else            // ���߽�
                                    break;
                            }

                            if (botNum == 0)                      // ��ͨ����
                                scoreMap[row][col] += 5;
                            else if (botNum == 1)                 // ���
                                scoreMap[row][col] += 10;
                            else if (botNum == 2)
                            {
                                if (emptyNum == 1)                // ����
                                    scoreMap[row][col] += 25;
                                else if (emptyNum == 2)
                                    scoreMap[row][col] += 50;  // ����
                            }
                            else if (botNum == 3)
                            {
                                if (emptyNum == 1)                // ����
                                    scoreMap[row][col] += 55;
                                else if (emptyNum == 2)
                                    scoreMap[row][col] += 10000; // ����
                            }
                            else if (botNum >= 4)
                                scoreMap[row][col] += 30000;   // ���壬Ӧ�þ���������ȼ�
                        }
                    }
                }
            }
        }
}

Chesspos AI::think()
{
    // ��������
    calculateScore();

    // ���������ҳ���������λ��
    int maxScore = 0;
    //std::vector<std::pair<int, int>> maxPoints;
    vector<Chesspos> maxPoints;
    int k = 0;

    int size = chess->getgradesize();
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++)
        {
            // ǰ������������ǿյ�
            if (chess->getchessdata(row, col) == 0) {
                if (scoreMap[row][col] > maxScore)          // ��������������
                {
                    maxScore = scoreMap[row][col];
                    maxPoints.clear();
                    maxPoints.push_back(Chesspos(row,col));
                }
                else if (scoreMap[row][col] == maxScore) {   // ����ж������������������
                    maxPoints.push_back(Chesspos(row,col));
                }
            }
        }
    }

    // ������ӣ�����ж����Ļ�
    int index = rand() % maxPoints.size();
    return maxPoints[index];
}
