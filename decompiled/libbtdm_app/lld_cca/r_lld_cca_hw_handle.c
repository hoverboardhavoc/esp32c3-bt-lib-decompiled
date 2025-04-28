/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_cca.o -> r_lld_cca_hw_handle
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_cca_hw_handle(undefined4 param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = rf_2_ble_chan_tab[param_2];
  if (*(char *)(p_lld_cca + 8) == cVar1) {
    uVar2 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
    if ((*(ushort *)(p_lld_cca + 4) & 0x10) == 0) {
      (**(code **)(_r_ip_funcs_p + 0x9b0))(param_1,cVar1,*(code **)(_r_ip_funcs_p + 0x9b0));
    }
    else {
      (**(code **)(_r_ip_funcs_p + 0x9ac))(param_1,cVar1,uVar2,*(code **)(_r_ip_funcs_p + 0x9ac));
      (**(code **)(_r_ip_funcs_p + 0x9b8))(cVar1,uVar2,*(code **)(_r_ip_funcs_p + 0x9b8));
    }
    if (*(ushort *)(p_lld_cca + 0x10) < *(ushort *)(p_lld_cca + 0xe)) {
                    /* WARNING: Could not recover jumptable at 0x00010b20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_ip_funcs_p + 0x9b4))(cVar1,uVar2,*(code **)(_r_ip_funcs_p + 0x9b4));
      return;
    }
  }
  return;
}

