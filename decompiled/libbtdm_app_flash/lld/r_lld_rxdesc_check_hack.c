/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_rxdesc_check_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_lld_rxdesc_check_hack(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = r_lld_rxdesc_check();
  if ((_LANCHOR1 != '\0') && (iVar1 != 0)) {
    lld_le_pkt_err_set(param_1,*(undefined1 *)(_p_lld_env + 0xd8));
  }
  return iVar1;
}

