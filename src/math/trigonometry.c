#include "trigonometry.h"

// Tabela de aproximação de seno com valores de 0° a 90° mapeados de 0 a 1000
// Exemplo: all_angle[90] == 1000 → representa sin(90°) = 1.0
// Os valores entre 0 e 90 graus são interpolados para permitir calcular seno/cosseno sem ponto flutuante
static const u16 all_angle[91] = {
	0, 17, 34, 52, 69, 87, 104, 121, 139, 156,
	173, 190, 207, 224, 241, 258, 275, 292, 309, 325,
	342, 358, 374, 390, 406, 422, 438, 453, 469, 484,
	500, 515, 529, 544, 559, 573, 587, 601, 615, 629,
	642, 656, 669, 681, 694, 707, 719, 731, 743, 754,
	766, 777, 788, 798, 809, 819, 829, 838, 848, 857,
	866, 874, 882, 891, 898, 906, 913, 920, 927, 933,
	939, 945, 951, 956, 961, 965, 970, 974, 978, 981,
	984, 987, 990, 992, 994, 996, 997, 998, 999, 999,
	1000
};

// Retorna o valor absoluto de um número com sinal
u16 abs(s16 v) {
	return (v < 0) ? -v : v;
}

// Calcula seno de um ângulo inteiro (0–359°) usando a tabela de lookup
// O resultado é um valor de -1000 a 1000 (representando -1.0 a 1.0)
// Usa simetria das funções trigonométricas para reduzir o domínio a 0–90°
s16 sin(u16 angle) {
	u16 angle_in_360 = abs(angle) % 360;

	u8 angle_sub = angle_in_360 % 90;   // deslocamento dentro do quadrante
	u8 angle_q = angle_in_360 / 90;     // número do quadrante (0–3)

	if (angle_sub == 0) {
		// Canto exato do quadrante (0°, 90°, 180°, 270°)
		if (angle_q % 2 == 0) {
			return all_angle[0]; // 0 ou 180 → seno = 0
		}

		s8 direction_q = angle_q >= 2 ? -1 : 1;
		return all_angle[90] * direction_q;
	}

	// Calcula valor baseado na simetria dentro do quadrante
	u8 a = (angle_q % 2 == 1) ? 90 - angle_sub : angle_sub;
	s8 direction_q = angle_q >= 2 ? -1 : 1;

	return all_angle[a] * direction_q;
}

// Calcula cosseno reutilizando a função seno (cos(x) = sin(x + 90°))
s16 cos(u16 angle) {
	return sin(angle + 90);
}

// Calcula a porcentagem de um valor: (value * percent) / 100
s16 percentageOf(s16 value, u8 percent) {
  return (value * percent) / 100;
}


// Calcula a posição orbital de um objeto com base em ângulo, distância e achatamento percentual
// - obj_x, obj_y: ponteiros para armazenar as coordenadas calculadas do objeto
// - r_point_x, r_point_y: ponto central ao redor do qual o objeto orbita
// - angle: ângulo atual da órbita (0–359°)
// - distance: distância do objeto até o centro de rotação (em pixels, valor inteiro)
// - x_scale: escala percentual no eixo X (para achatamento horizontal, 100 = normal)
// - y_scale: escala percentual no eixo Y (para achatamento vertical, 100 = normal)
void TrigonometryOrbital_computePositionEx(
  u16 *obj_x,
  u16 *obj_y,
  u16 r_point_x,
  u16 r_point_y,
  u16 angle,
  u8 distance,
  u8 x_scale,  
  u8 y_scale   
) {
  s16 sin_angle = sin(angle);
  s16 cos_angle = cos(angle);

  // Evita overflow ao multiplicar por distância:
  // divide distância em dezenas e unidades para manter os valores dentro do limite de s16
  u8 distance_ten = distance / 10;
  u8 distance_unit = distance % 10;

  // Calcula deslocamento proporcional ao seno e cosseno com base na distância
  s16 sin_distance = ((distance_ten * sin_angle) / 100) + ((distance_unit * sin_angle) / 1000);
  s16 cos_distance = ((distance_ten * cos_angle) / 100) + ((distance_unit * cos_angle) / 1000);

  // Aplica escala percentual nos eixos X e Y (achatamento)
  sin_distance = percentageOf(sin_distance, x_scale);
  cos_distance = percentageOf(cos_distance, y_scale);

  *obj_x = r_point_x + sin_distance;
  *obj_y = r_point_y + cos_distance;

}

// Versão simplificada da função orbital, com escala padrão (100%) nos dois eixos
// Calcula a posição orbital de um objeto com base em ângulo e distância
// - obj_x, obj_y: ponteiros para armazenar as coordenadas calculadas do objeto
// - r_point_x, r_point_y: ponto central ao redor do qual o objeto orbita
// - angle: ângulo atual da órbita (0–359°)
// - distance: distância do objeto até o centro de rotação (em pixels, valor inteiro)
void TrigonometryOrbital_computePosition(
  u16 *obj_x,
  u16 *obj_y,
  u16 r_point_x,
  u16 r_point_y,
  u16 angle,
  u8 distance
) {
  TrigonometryOrbital_computePositionEx(
    obj_x, obj_y,
    r_point_x, r_point_y,
    angle,
    distance,
    100, 100
  );
}
