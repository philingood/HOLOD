#include <math.h>

#include "hol3.h"

void print_data(void)
{
int ii;
double pp = 273.15;

 fprintf(fout,"\n Расчет параметров течения и теплового потока в сечениях\n");
 fprintf(fout," Скорoсть звука в критическом сечении %7.2f м/с\n",akr);
 fprintf(fout,"%c\n",15);
 fprintf(fout,"/--------------------------------------------------------------------------------------------------\\\n");
 fprintf(fout,"| Hомер |   La   | Скорость |Температура|Давление |Плотность|       Тепловой поток, кВт/м2         |\n");
 fprintf(fout,"|сечения|        |   м/с    |     К     |   МПа   |  кг/м3  |Конвективный| Лучистый   | Суммарный  |\n");
 fprintf(fout,"|-------+--------+----------+-----------+---------+---------+------------+------------+------------|\n");
 for(ii=0;ii<n;ii++){
	 fprintf(fout,"|   %2d  | %6.3f |  %6.1f  |    %5.0f  | %7.4f | %8.4f|%12.2f|%12.2f|%12.2f|\n",
		ii+1,
		La[ii],
		La[ii]*akr,
		T[ii],
		(P[ii]/1e6),
		(Rgc(ii)*T[ii]/P[ii]),
		Q[ii]/1e3,
		Ql[ii]/1e3,
		(Q[ii]+Ql[ii])/1e3
		);
	}
  fprintf(fout,"\\-------------------------------------------------------------------------------------------------/\n");
  fprintf(fout,"%c\n",18);
  fprintf(fout,"\n");

  fprintf(fout," Параметры гидравлического тракта и коэффициент теплоотдачи к охладителю\n");
  fprintf(fout,"%c\n",15);
  fprintf(fout,"/----------------------------------------------------------------------------------------------------------\\\n");
  fprintf(fout,"|Номер|Ширина | Шаг  |Площадь про-|Гидравлическ|    Ro*W    |     Re     |К-т теплоот-|То же с уче-|Kоэф-т |\n");
  fprintf(fout,"| сеч.|зазора |      |ходн.сечения|  диаметр   |   кг/(м2*c)|            |дачи в охлад|том оребрен.|эффект.|\n");
  fprintf(fout,"|     |  мм   | мм   |     мм2    |     мм     |            |            |   Вт/(м2*K)| Вт/(м2*K)  |оребрен|\n");
  fprintf(fout,"|-----+-------+-------------------+------------+------------+------------+------------+------------+-------|\n");
  for(ii=vm;ii<om;ii++)
  fprintf(fout,"|%5d|%7.3f|%6.2f|%12.6f|%12.6f|%12.4f|%12.4f|%12.4f|%12.4f|%7.4f|\n",
		ii+1,Ak[ii]*1000.,tN[ii]*1000.,fS[ii]*1e6,Dg[ii]*1e3,roW[ii],Re[ii],Alp[ii]/Eta[ii],Alp[ii],Eta[ii]);
  fprintf(fout,"\\----------------------------------------------------------------------------------------------------------/\n");
  fprintf(fout,"%c\n",18);
  fprintf(fout," Температуры стенки камеры и охладителя и потери давления по тракту:\n");
  fprintf(fout," (падение давления между участками i и j записывается в строку \n"
	       " сечения j, то есть следующего по направлению течения охладителя)\n");
  fprintf(fout,"%c\n",15);
  fprintf(fout,"/------------------------------------------------------------------------------------------------\\\n");
  fprintf(fout,"|Номер|Tемпература |Tемпература |Температура |Температура |Температура |Температура |Падение дав-|\n");
  fprintf(fout,"| сеч.|стенки со   |стенки со   |стенки со   |стенки со   | охладителя | охладителя |  ления на  |\n");
  fprintf(fout,"|     |стороны газа|стороны газа|стор.жид-сти|стор.жид-сти|            |            |   участке  |\n");
  fprintf(fout,"|     |     K      |      C     |     K      |     C      |     K      |     C      |     Па     |\n");
  fprintf(fout,"|-----+------------+------------+------------+------------|------------+------------+------------|\n");

  for(ii=vm;ii<om;ii++)
        fprintf(fout,"|%5d|%12.3f|%12.3f|%12.3f|%12.3f|%12.3f|%12.3f|%12.3f|\n",
                ii+1,
                Tct[ii],Tct[ii]-pp,
                Tctg[ii],Tctg[ii]-pp,
                Tg[ii],Tg[ii]-pp,
                dP[ii]);
  fprintf(fout,"\\-----------------------------------------------------------------------------------------------/\n");
  fprintf(fout,"%c\n",18);

}
