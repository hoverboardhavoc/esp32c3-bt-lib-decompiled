/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld.o -> lld_peer_rpa_res
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool lld_peer_rpa_res(void *param_1,int param_2)

{
  int iVar1;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  undefined2 uStack_14;
  undefined1 uStack_12;
  
  iVar1 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
  if ((*(ushort *)(iVar1 + param_2 * 0x34) >> 1 & 1) == 0) {
    return false;
  }
  (**(code **)(_r_plf_funcs_p + 0xbc))(param_2 * 0x34 + 0xc62,*(code **)(_r_plf_funcs_p + 0xbc));
  uStack_18 = *(undefined1 *)((int)param_1 + 3);
  uStack_17 = *(undefined1 *)((int)param_1 + 4);
  uStack_14 = 0;
  uStack_16 = *(undefined1 *)((int)param_1 + 5);
  uStack_12 = 0;
  rw_crypto_aes_encrypt_sync(&uStack_18,3,&uStack_14);
  iVar1 = memcmp(&uStack_14,param_1,3);
  return iVar1 == 0;
}

