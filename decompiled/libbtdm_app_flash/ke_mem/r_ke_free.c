/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
    r_assert_param(0,"ke_mem.c",0x19a);
  }
  psVar8 = param_1 + -2;
  if (param_1[-2] != -0x7cc8) {
    r_assert_param(param_1,"ke_mem.c",0x1a1);
  }
  param_1[-2] = -0xff1;
  uVar1 = param_1[-1];
  uVar6 = 0;
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  do {
    while (iVar4 = r_ke_mem_is_in_heap(uVar6,param_1), iVar4 == 0) {
      uVar6 = uVar6 + 1 & 0xff;
      if (uVar6 == 4) {
_L69:
        r_assert_err(0,"ke_mem.c",0x1c1);
        psVar7 = (short *)0x0;
        goto _L73;
      }
    }
    psVar2 = *(short **)(r_assert_err + (uVar6 + 4) * 4);
    if (uVar6 == 4) {
      if (psVar2 == (short *)0x0) goto _L69;
      break;
    }
  } while (psVar2 == (short *)0x0);
  if (param_1 <= psVar2) {
    r_assert_err(0,"ke_mem.c",0x1c2);
  }
  psVar7 = (short *)0x0;
  do {
    psVar3 = psVar2;
    if (psVar3 == (short *)0x0) {
_L73:
      *(short **)(psVar7 + 2) = psVar8;
      param_1[0] = 0;
      param_1[1] = 0;
      *(short **)(param_1 + 2) = psVar7;
      param_1[-1] = uVar1;
      param_1[-2] = -0x5aa6;
_L78:
                    /* WARNING: Could not recover jumptable at 0x000104ae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_osi_funcs_p + 0x18))();
      return;
    }
    if (*psVar3 != -0x5aa6) {
      r_assert_err(0,"ke_mem.c",0x1ca);
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
      goto _L78;
    }
    if (psVar8 < psVar3) {
      if (psVar7 == (short *)0x0) {
        r_assert_err(0,"ke_mem.c",0x1e5);
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
      goto _L78;
    }
    psVar2 = *(short **)(psVar3 + 2);
    psVar7 = psVar3;
  } while( true );
}

