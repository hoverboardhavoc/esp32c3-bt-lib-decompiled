/*
 * Last changed at upstream commit a075a8fde411bdd92973051edf2cd234601b259c
 * https://github.com/espressif/esp32c3-bt-lib/commit/a075a8fde411bdd92973051edf2cd234601b259c
 * Upstream date: 2023-11-30 21:15:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(70ab55f)
 * Source: libbtdm_app -> lld.o -> lld_peer_rpa_res
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool lld_peer_rpa_res(void *param_1,uint param_2)

{
  int iVar1;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  uint uStack_14;
  
  uStack_14 = param_2;
  iVar1 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
  if ((*(ushort *)(iVar1 + uStack_14 * 0x34) >> 1 & 1) == 0) {
    return false;
  }
  (**(code **)(_r_plf_funcs_p + 0xbc))
            (uStack_14 * 0x34 + 0xc62 & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
  uStack_18 = *(undefined1 *)((int)param_1 + 3);
  uStack_17 = *(undefined1 *)((int)param_1 + 4);
  uStack_16 = *(undefined1 *)((int)param_1 + 5);
  uStack_14 = uStack_14 & 0xff000000;
  rw_crypto_aes_encrypt_sync(&uStack_18,3,&uStack_14);
  iVar1 = memcmp(&uStack_14,param_1,3);
  return iVar1 == 0;
}

