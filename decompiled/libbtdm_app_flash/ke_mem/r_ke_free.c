/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> ke_mem.o -> r_ke_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ke_free(int *param_1)

{
  ushort uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  short sVar5;
  int *piVar6;
  uint uVar7;
  int *piVar8;
  
  if (param_1 == (int *)0x0) {
    r_assert_param(0,"ke_mem.c",0x19b);
  }
  iVar4 = r_sdk_config_get_opts_ext();
  piVar6 = param_1 + -1;
  if ((*(uint *)(iVar4 + 0x28) & 2) != 0) {
    iVar4 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar4 + 0x2c) < 3) {
      r_ble_log_internal_x2
                (0x40250007,param_1,CONCAT22((short)param_1[-1],*(short *)((int)param_1 + -2)));
    }
  }
  if ((short)param_1[-1] != -0x7cc8) {
    r_assert_param(param_1,"ke_mem.c",0x1a3);
  }
  *(short *)(param_1 + -1) = -0xff1;
  uVar1 = *(ushort *)((int)param_1 + -2);
  uVar7 = 0;
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  do {
    while (iVar4 = r_ke_mem_is_in_heap(uVar7,param_1), iVar4 != 0) {
      piVar2 = *(int **)(r_ble_log_internal_x2 + (uVar7 + 4) * 4);
      if (piVar2 != (int *)0x0) {
        if (param_1 <= piVar2) {
          r_assert_err(0,"ke_mem.c",0x1c4);
        }
        piVar8 = (int *)0x0;
        goto _L81;
      }
    }
    uVar7 = uVar7 + 1 & 0xff;
  } while (uVar7 != 4);
  r_assert_err("ke_mem.c",0x1c3);
  piVar8 = (int *)0x0;
_L93:
  piVar8[1] = (int)piVar6;
  *param_1 = 0;
  param_1[1] = (int)piVar8;
  *(ushort *)((int)param_1 + -2) = uVar1;
  *(short *)(param_1 + -1) = -0x5aa6;
_L86:
                    /* WARNING: Could not recover jumptable at 0x00010592. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return;
_L81:
  piVar3 = piVar2;
  if (piVar3 == (int *)0x0) goto _L93;
  if ((short)*piVar3 != -0x5aa6) {
    r_assert_err(0,"ke_mem.c",0x1cc);
  }
  if ((int *)((uint)*(ushort *)((int)piVar3 + 2) + (int)piVar3) == piVar6) {
    uVar7 = (uint)*(ushort *)((int)piVar3 + 2) + (uint)uVar1;
    iVar4 = piVar3[1];
    sVar5 = (short)(uVar7 * 0x10000 >> 0x10);
    *(short *)((int)piVar3 + 2) = sVar5;
    if (iVar4 == (uVar7 & 0xffff) + (int)piVar3) {
      *(short *)((int)piVar3 + 2) = sVar5 + *(short *)(iVar4 + 2);
      iVar4 = *(int *)(iVar4 + 4);
      piVar3[1] = iVar4;
      if (iVar4 != 0) {
        *(int **)(iVar4 + 8) = piVar3;
      }
    }
    goto _L86;
  }
  if (piVar6 < piVar3) {
    if (piVar8 == (int *)0x0) {
      r_assert_err(0,"ke_mem.c",0x1e7);
    }
    piVar8[1] = (int)piVar6;
    *(short *)(param_1 + -1) = -0x5aa6;
    param_1[1] = (int)piVar8;
    if (piVar3 == (int *)((int)piVar6 + (uint)uVar1)) {
      iVar4 = piVar3[1];
      *param_1 = iVar4;
      if (iVar4 != 0) {
        *(int **)(iVar4 + 8) = piVar6;
      }
      *(ushort *)((int)param_1 + -2) = *(short *)((int)piVar3 + 2) + uVar1;
    }
    else {
      *param_1 = (int)piVar3;
      piVar3[2] = (int)piVar6;
      *(ushort *)((int)param_1 + -2) = uVar1;
    }
    goto _L86;
  }
  piVar2 = (int *)piVar3[1];
  piVar8 = piVar3;
  goto _L81;
}

