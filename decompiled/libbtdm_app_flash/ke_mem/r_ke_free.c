/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> ke_mem.o -> r_ke_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ke_free(short *param_1)

{
  ushort uVar1;
  short *psVar2;
  short *psVar3;
  int iVar4;
  short sVar5;
  uint uVar6;
  short *psVar7;
  short *psVar8;
  
  if (param_1 == (short *)0x0) {
    r_assert_param(0,"ke_mem.c",0x19b);
  }
  iVar4 = r_sdk_config_get_opts_ext();
  psVar8 = param_1 + -2;
  if (((*(uint *)(iVar4 + 0x28) & 2) != 0) &&
     (iVar4 = r_sdk_config_get_opts_ext(), *(byte *)(iVar4 + 0x2c) < 3)) {
    r_ble_log_internal_x2(0x40250007,param_1,CONCAT22(param_1[-2],param_1[-1]));
  }
  if (param_1[-2] != -0x7cc8) {
    r_assert_param(param_1,"ke_mem.c",0x1a3);
  }
  param_1[-2] = -0xff1;
  uVar1 = param_1[-1];
  uVar6 = 0;
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  do {
    while (iVar4 = r_ke_mem_is_in_heap(uVar6,param_1), iVar4 == 0) {
      uVar6 = uVar6 + 1 & 0xff;
      if (uVar6 == 4) {
_L78:
        r_assert_err(0,"ke_mem.c",0x1c3);
        psVar2 = (short *)0x0;
        goto _L79;
      }
    }
    psVar2 = *(short **)(r_ble_log_internal_x2 + (uVar6 + 4) * 4);
    if (uVar6 == 4) {
      if (psVar2 == (short *)0x0) goto _L78;
      break;
    }
  } while (psVar2 == (short *)0x0);
_L79:
  if (param_1 <= psVar2) {
    r_assert_err(0,"ke_mem.c",0x1c4);
  }
  psVar7 = (short *)0x0;
  do {
    psVar3 = psVar2;
    if (psVar3 == (short *)0x0) {
      *(short **)(psVar7 + 2) = psVar8;
      param_1[0] = 0;
      param_1[1] = 0;
      *(short **)(param_1 + 2) = psVar7;
      param_1[-1] = uVar1;
      param_1[-2] = -0x5aa6;
_L86:
                    /* WARNING: Could not recover jumptable at 0x00010586. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
      return;
    }
    if (*psVar3 != -0x5aa6) {
      r_assert_err(0,"ke_mem.c",0x1cc);
    }
    if ((short *)((uint)(ushort)psVar3[1] + (int)psVar3) == psVar8) {
      uVar6 = (uint)(ushort)psVar3[1] + (uint)uVar1;
      iVar4 = *(int *)(psVar3 + 2);
      sVar5 = (short)(uVar6 * 0x10000 >> 0x10);
      psVar3[1] = sVar5;
      if (iVar4 == (uVar6 & 0xffff) + (int)psVar3) {
        psVar3[1] = sVar5 + *(short *)(iVar4 + 2);
        iVar4 = *(int *)(iVar4 + 4);
        *(int *)(psVar3 + 2) = iVar4;
        if (iVar4 != 0) {
          *(short **)(iVar4 + 8) = psVar3;
        }
      }
      goto _L86;
    }
    if (psVar8 < psVar3) {
      if (psVar7 == (short *)0x0) {
        r_assert_err(0,"ke_mem.c",0x1e7);
      }
      *(short **)(psVar7 + 2) = psVar8;
      param_1[-2] = -0x5aa6;
      *(short **)(param_1 + 2) = psVar7;
      if (psVar3 == (short *)((int)psVar8 + (uint)uVar1)) {
        *(undefined4 *)param_1 = *(undefined4 *)(psVar3 + 2);
        if (*(int *)(psVar3 + 2) != 0) {
          *(short **)(*(int *)(psVar3 + 2) + 8) = psVar8;
        }
        param_1[-1] = psVar3[1] + uVar1;
      }
      else {
        *(short **)param_1 = psVar3;
        *(short **)(psVar3 + 4) = psVar8;
        param_1[-1] = uVar1;
      }
      goto _L86;
    }
    psVar2 = *(short **)(psVar3 + 2);
    psVar7 = psVar3;
  } while( true );
}

