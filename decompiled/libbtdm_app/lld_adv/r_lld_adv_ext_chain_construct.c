/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_ext_chain_construct
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_ext_chain_construct(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined1 uVar3;
  code *pcVar4;
  
  iVar2 = *(int *)(&lld_adv_env + param_1 * 4);
  bVar1 = *(byte *)(iVar2 + 0x74);
  uVar3 = (**(code **)(_r_ip_funcs_p + 0x230))(*(code **)(_r_ip_funcs_p + 0x230));
  *(undefined1 *)(iVar2 + 0x91) = uVar3;
  *(undefined2 *)(iVar2 + 0x7a) = 0;
  *(undefined2 *)(iVar2 + 0x7c) = 0;
  *(undefined4 *)(iVar2 + 0x6c) = 0;
  if ((bVar1 & 3) == 0) {
    pcVar4 = *(code **)(_r_ip_funcs_p + 0x76c);
  }
  else if ((bVar1 & 1) == 0) {
    if ((bVar1 & 2) == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x69d,*(code **)(_r_plf_funcs_p + 8));
      goto _L539;
    }
    pcVar4 = *(code **)(_r_ip_funcs_p + 0x774);
  }
  else {
    pcVar4 = *(code **)(_r_ip_funcs_p + 0x770);
  }
  (*pcVar4)(param_1,pcVar4);
_L539:
  *(uint *)(*(int *)(&lld_adv_env + param_1 * 4) + 0x10) =
       *(int *)(iVar2 + 0x6c) * 2 + (uint)_sdk_cfg_priv_opts;
  return;
}

