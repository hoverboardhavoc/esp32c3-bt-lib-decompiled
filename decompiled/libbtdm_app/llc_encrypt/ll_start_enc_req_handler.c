/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_encrypt.o -> ll_start_enc_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ll_start_enc_req_handler(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar1 + 0x20) == '\0') {
    return 0x24;
  }
  if ((*(ushort *)(*(int *)(&llc_env + param_1 * 4) + 0x42) & 1) == 0) {
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(1,param_2);
    if (iVar1 == 3) {
      uVar3 = 0x3d;
      uVar2 = 0x13;
      pcVar4 = *(code **)(_r_ip_funcs_p + 0x59c);
_L181:
      (*pcVar4)(param_1,uVar2,uVar3,pcVar4);
      return 0;
    }
  }
  else {
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(0,param_2);
    if (iVar1 == 3) {
      uVar3 = 0;
      uVar2 = 5;
      pcVar4 = *(code **)(_r_ip_funcs_p + 0x594);
      goto _L181;
    }
  }
  return 0x24;
}

