
class Solution {
public:
	const double DBL_MAX = std::numeric_limits<double>::max();
	const double DBL_MIN = std::numeric_limits<double>::min();

	double delta = 0.0001;

	struct Line {
		double w;
		double b;
		Line() :w(0), b(0) {}
		Line(double a, double c) : w(a), b(c) {}
		bool operator==(const Line& lhs) { return abs(w - lhs.w) <0.0001 &&abs(b - lhs.b) < 0.0001; }
		bool operator!=(const Line& lhs) { return !(*this == lhs); }
	};

	bool pointsEqual(const Point& lhs, const Point& rhs)
	{
		return lhs.x == rhs.x && lhs.y == rhs.y;
	}

	int maxPoints(vector<Point>& points) {
		int length = points.size();
		if (length <= 2) return length;
		int maxNum = 0;

		vector<pair<Point, int>> newPoints;
		for (int i = 0; i < length; i++)
		{
			int j = 0;
			for (; j < newPoints.size(); j++)
			{
				if (pointsEqual(points[i], newPoints[j].first))
				{
					newPoints[j].second++;
					if (maxNum < newPoints[j].second) maxNum = newPoints[j].second;
					break;
				}
			}
			if (j == newPoints.size())
			{
				newPoints.push_back(make_pair(points[i], 1));
			}
		}

		vector<vector<pair<Line, int>>> newLines; // lines starting from i 

		int newPointsLength = newPoints.size();
		// Init. Every point has a line across itself.
		for (int i = 0; i < newPointsLength; i++)
		{
			vector<pair<Line, int>> tmp;
			tmp.push_back(make_pair(Line(0, DBL_MIN), 1));
			newLines.push_back(tmp);
		}

		// iterate from point with duplicates
		for (int i = 0; i<newPointsLength; i++)
		{
			// Compare between points
			for (int j = 0; j<i; j++)
			{
				double tmpK, tmpB;
				// Calculate attr of line
				if (abs(newPoints[i].first.x - newPoints[j].first.x)<delta)
				{
					tmpK = DBL_MAX;
					tmpB = newPoints[i].first.x;
				}
				else
				{
					tmpK = (double)(newPoints[i].first.y - newPoints[j].first.y) / (newPoints[i].first.x - newPoints[j].first.x);
					tmpB = (double)(newPoints[i].first.y - tmpK * newPoints[i].first.x);
				}
				Line l(tmpK, tmpB);

				int tmpLength = newLines[i].size();
				int k = 1;
				for (; k < tmpLength; k++)
				{
					if (newLines[i][k].first == l)
					{
						newLines[i][k].second += newPoints[j].second;
						if (maxNum < newLines[i][k].second) maxNum = newLines[i][k].second;
						break;
					}
				}
				if (k == tmpLength)
				{
					newLines[i].push_back(make_pair(l, newPoints[j].second + newPoints[i].second));
					if (maxNum < newLines[i][k].second) maxNum = newLines[i][k].second;
				}
			}
		}

		return maxNum;

	}
};

