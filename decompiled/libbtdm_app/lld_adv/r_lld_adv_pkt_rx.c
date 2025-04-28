/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_pkt_rx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_adv_pkt_rx(int param_1)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  while (iVar1 = (**(code **)(_r_ip_funcs_p + 0x2a4))(param_1,*(code **)(_r_ip_funcs_p + 0x2a4)),
        iVar1 != 0) {
    iVar1 = (uint)*(byte *)(_p_lld_env + 0xd8) * 0x14;
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    if ((*(ushort *)(iVar1 + 2 + iVar2) & 0x603d) == 0) {
      iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar3 = *(ushort *)(iVar1 + 4 + iVar2) & 0xf;
      if (uVar3 == 5) {
        uVar4 = (**(code **)(_r_ip_funcs_p + 0x1c8))(param_1,*(code **)(_r_ip_funcs_p + 0x1c8));
      }
      else if ((*(char *)(*(int *)(&lld_adv_env + param_1 * 4) + 0x8a) != '\0') && (uVar3 == 3)) {
        (**(code **)(_r_ip_funcs_p + 0x1cc))(param_1,*(code **)(_r_ip_funcs_p + 0x1cc));
      }
    }
    (**(code **)(_r_ip_funcs_p + 0x2a8))(*(code **)(_r_ip_funcs_p + 0x2a8));
  }
  return uVar4;
}

