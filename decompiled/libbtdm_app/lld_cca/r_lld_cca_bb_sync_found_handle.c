/*
 * Last changed at upstream commit 040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * https://github.com/espressif/esp32c3-bt-lib/commit/040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * Upstream date: 2023-08-03 10:45:08 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ff6efe7)
 * Source: libbtdm_app -> lld_cca.o -> r_lld_cca_bb_sync_found_handle
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_cca_bb_sync_found_handle(void)

{
  int iVar1;
  byte *pbVar2;
  undefined4 uVar3;
  
  pbVar2 = (byte *)(*(int *)(p_lld_cca + 0x28) + (uint)*(byte *)(p_lld_cca + 8) * 0xc);
  if ((*pbVar2 & 0x10) != 0) {
    uVar3 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
    iVar1 = _r_ip_funcs_p;
    *(undefined4 *)(pbVar2 + 4) = uVar3;
    (**(code **)(iVar1 + 0x978))(0,*(code **)(iVar1 + 0x978));
    *pbVar2 = *pbVar2 & 0xe7;
  }
  return;
}

