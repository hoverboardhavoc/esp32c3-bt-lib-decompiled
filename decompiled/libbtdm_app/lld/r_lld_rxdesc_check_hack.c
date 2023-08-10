/*
 * Last changed at upstream commit 0cfac1b21ebc995e8e9aa040ab1ab29deee4f580
 * https://github.com/espressif/esp32c3-bt-lib/commit/0cfac1b21ebc995e8e9aa040ab1ab29deee4f580
 * Upstream date: 2023-08-10 21:56:13 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(59725b5)
 * Source: libbtdm_app -> lld.o -> r_lld_rxdesc_check_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_lld_rxdesc_check_hack(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = r_lld_rxdesc_check();
  if ((_LANCHOR0 != '\0') && (iVar2 != 0)) {
    bVar1 = *(byte *)(_p_lld_env + 0xd8);
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    lld_le_pkt_err_set(param_1,*(undefined2 *)((uint)bVar1 * 0x14 + 2 + iVar3));
  }
  return iVar2;
}

