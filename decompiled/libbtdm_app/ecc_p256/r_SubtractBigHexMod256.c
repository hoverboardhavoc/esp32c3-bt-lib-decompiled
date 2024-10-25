/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> ecc_p256.o -> r_SubtractBigHexMod256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_SubtractBigHexMod256(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  uint uVar6;
  
  if (*(int *)(param_1 + 0x28) == 0) {
    if (*(int *)(param_2 + 0x28) != 0) {
      (**(code **)(_r_modules_funcs_p + 0x350))(*(code **)(_r_modules_funcs_p + 0x350));
      goto _L109;
    }
    uVar4 = *(uint *)(param_1 + 0x24);
    if (uVar4 <= *(uint *)(param_2 + 0x24)) {
      if (uVar4 < *(uint *)(param_2 + 0x24)) {
_L92:
        pcVar5 = *(code **)(_r_modules_funcs_p + 0x3ac);
        iVar3 = param_2;
        param_2 = param_1;
_L112:
        (*pcVar5)(iVar3,param_2,param_3,pcVar5);
_L110:
        *(undefined4 *)(param_3 + 0x28) = 1;
                    /* WARNING: Could not recover jumptable at 0x00010554. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(_r_modules_funcs_p + 0x358))(param_3);
        return;
      }
      for (uVar4 = 0x11 - uVar4; uVar4 < 0x11; uVar4 = uVar4 + 1) {
        uVar2 = *(ushort *)(param_2 + uVar4 * 2);
        uVar1 = *(ushort *)(uVar4 * 2 + param_1);
        if (uVar1 < uVar2) goto _L92;
        if (uVar2 < uVar1) break;
      }
    }
    pcVar5 = *(code **)(_r_modules_funcs_p + 0x3ac);
    iVar3 = param_1;
    param_1 = param_2;
  }
  else {
    if (*(int *)(param_2 + 0x28) == 0) {
      (**(code **)(_r_modules_funcs_p + 0x350))(*(code **)(_r_modules_funcs_p + 0x350));
      goto _L110;
    }
    uVar4 = *(uint *)(param_2 + 0x24);
    if (uVar4 <= *(uint *)(param_1 + 0x24)) {
      if (uVar4 < *(uint *)(param_1 + 0x24)) {
_L99:
        pcVar5 = *(code **)(_r_modules_funcs_p + 0x3ac);
        iVar3 = param_1;
        goto _L112;
      }
      for (uVar4 = 0x11 - uVar4; uVar4 < 0x11; uVar4 = uVar4 + 1) {
        uVar2 = *(ushort *)(param_1 + uVar4 * 2);
        uVar1 = *(ushort *)(uVar4 * 2 + param_2);
        if (uVar1 < uVar2) goto _L99;
        if (uVar2 < uVar1) break;
      }
    }
    pcVar5 = *(code **)(_r_modules_funcs_p + 0x3ac);
    iVar3 = param_2;
  }
  (*pcVar5)(iVar3,param_1,param_3,pcVar5);
_L109:
  uVar4 = _r_plf_funcs_p;
  uVar6 = *(uint *)(param_3 + 0x24);
  *(undefined4 *)(param_3 + 0x28) = 0;
  if (uVar6 <= uVar4) {
    if (uVar6 < uVar4) {
      return;
    }
    for (uVar6 = 0x11 - uVar6; uVar6 < 0x11; uVar6 = uVar6 + 1) {
      uVar2 = *(ushort *)(uVar6 * 2 + param_3);
      if (uVar2 < *(ushort *)(&bigHexP256 + uVar6 * 2)) {
        return;
      }
      if (*(ushort *)(&bigHexP256 + uVar6 * 2) < uVar2) break;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00010532. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x3b8))(param_3,&bigHexP256);
  return;
}

