/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> sch_arb.o -> r_sch_arb_elt_cancel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_arb_elt_cancel(int param_1)

{
  ushort uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  int *piVar11;
  int *piVar12;
  
  piVar10 = (int *)_r_co_list_insert_after;
  piVar3 = (int *)0;
_L23:
  do {
    do {
      iVar4 = (int)piVar3;
      piVar3 = piVar10;
      if (piVar3 == (int *)0x0) {
        if (_r_co_list_insert_after == 0) {
          return;
        }
        r_rwip_sw_int_req();
        return;
      }
      uVar1 = *(ushort *)(piVar3 + 5);
      piVar10 = (int *)*piVar3;
    } while ((uVar1 >> 0xe == 0) || (uVar7 = (int)(uint)uVar1 >> 4 & 0x3f, uVar7 == 0));
    uVar8 = (uVar7 - 1) * 0x10;
    uVar7 = uVar1 & 0xfffffc0f;
    *(byte *)((int)piVar3 + 0x16) = *(char *)((int)piVar3 + 0x16) + ((byte)uVar1 & 0xf);
    *(ushort *)(piVar3 + 5) = (ushort)uVar8 | (ushort)uVar7;
    piVar2 = (int *)param_1;
    piVar12 = (int *)0;
    while ((piVar11 = piVar2, piVar11 != (int *)0x0 &&
           (iVar5 = r_sch_arb_conflict_check(piVar3,piVar11), iVar5 != 0))) {
      if (iVar5 != 5) {
        uVar9 = (uint)(piVar11[2] + piVar11[4]) / 0x271 + piVar11[1] +
                (uint)((uint)piVar3[2] < (uint)(piVar11[2] + piVar11[4]) % 0x271) & 0xfffffff;
        piVar3[1] = uVar9;
        if (1 < (uVar8 & 0xffff | uVar7) >> 0xe) {
          uVar6 = piVar3[3] - uVar9 & 0xfffffff;
          if (0x8000000 < uVar6) {
            uVar6 = -(uVar9 - piVar3[3] & 0xfffffff);
          }
          if ((int)uVar6 < (int)((uint)piVar3[4] / 0x271)) goto _L23;
        }
      }
      piVar2 = (int *)*piVar11;
      piVar12 = piVar11;
    }
    r_co_list_extract_after(&sch_arb_env,iVar4,piVar3);
    r_co_list_insert_after(&sch_arb_env,piVar12,piVar3);
    piVar3 = (int *)iVar4;
  } while( true );
}

