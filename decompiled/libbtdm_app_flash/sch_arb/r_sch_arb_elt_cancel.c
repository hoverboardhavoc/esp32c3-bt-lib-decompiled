/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  int *piVar12;
  
  piVar9 = (int *)_r_co_list_insert_after;
  piVar3 = (int *)0;
_L17:
  do {
    do {
      iVar11 = (int)piVar3;
      piVar3 = piVar9;
      if (piVar3 == (int *)0x0) {
        if (_r_co_list_insert_after == 0) {
          return;
        }
        r_rwip_sw_int_req();
        return;
      }
      uVar1 = *(ushort *)(piVar3 + 5);
      piVar9 = (int *)*piVar3;
    } while ((uVar1 >> 0xe == 0) || (uVar6 = (int)(uint)uVar1 >> 4 & 0x3f, uVar6 == 0));
    uVar7 = (uVar6 - 1) * 0x10;
    uVar6 = uVar1 & 0xfffffc0f;
    *(byte *)((int)piVar3 + 0x16) = ((byte)uVar1 & 0xf) + *(char *)((int)piVar3 + 0x16);
    *(ushort *)(piVar3 + 5) = (ushort)uVar7 | (ushort)uVar6;
    piVar2 = (int *)param_1;
    piVar12 = (int *)0;
    while ((piVar10 = piVar2, piVar10 != (int *)0x0 &&
           (iVar4 = r_sch_arb_conflict_check(piVar3,piVar10), iVar4 != 0))) {
      if (iVar4 != 5) {
        uVar8 = (uint)(piVar10[2] + piVar10[4]) / 0x271 + piVar10[1];
        if ((uint)piVar3[2] < (uint)(piVar10[2] + piVar10[4]) % 0x271) {
          uVar8 = uVar8 + 1;
        }
        uVar8 = uVar8 & 0xfffffff;
        piVar3[1] = uVar8;
        if (1 < (uVar7 & 0xffff | uVar6) >> 0xe) {
          uVar5 = piVar3[3] - uVar8 & 0xfffffff;
          if (0x8000000 < uVar5) {
            uVar5 = -(uVar8 - piVar3[3] & 0xfffffff);
          }
          if ((int)uVar5 < (int)((uint)piVar3[4] / 0x271)) goto _L17;
        }
      }
      piVar2 = (int *)*piVar10;
      piVar12 = piVar10;
    }
    r_co_list_extract_after(&sch_arb_env,iVar11,piVar3);
    r_co_list_insert_after(&sch_arb_env,piVar12,piVar3);
    piVar3 = (int *)iVar11;
  } while( true );
}

