/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  
  iVar1 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
  if ((*(ushort *)(param_2 * 0x34 + iVar1) >> 1 & 1) == 0) {
    return false;
  }
  (**(code **)(_r_plf_funcs_p + 0xbc))
            (param_2 * 0x34 + 0xc62U & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
  uStack_18 = *(undefined1 *)((int)param_1 + 3);
  uStack_17 = *(undefined1 *)((int)param_1 + 4);
  uStack_16 = *(undefined1 *)((int)param_1 + 5);
  rw_crypto_aes_encrypt_sync(&uStack_18,3,&stack0xffffffec);
  iVar1 = memcmp(&stack0xffffffec,param_1,3);
  return iVar1 == 0;
}

