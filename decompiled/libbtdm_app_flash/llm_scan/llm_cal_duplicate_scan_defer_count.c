/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_scan.o -> llm_cal_duplicate_scan_defer_count
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void llm_cal_duplicate_scan_defer_count(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(char *)(_p_llm_env + 0xd7) != '\x02') {
    iVar1 = r_sdk_config_get_opts_ext();
    if (*(short *)(iVar1 + 0x16) != 0) {
      iVar1 = r_llm_le_scan_duplicate_opt_get();
      iVar2 = r_sdk_config_get_opts_ext();
      param_1 = (int)((uint)*(ushort *)(iVar2 + 0x16) * 0x640) / param_1;
      if (param_1 == 0) {
        *(undefined4 *)(iVar1 + 0x18) = 1;
      }
      else {
        *(int *)(iVar1 + 0x18) = param_1;
      }
      *(undefined4 *)(iVar1 + 0x1c) = 0;
    }
    return;
  }
  return;
}

