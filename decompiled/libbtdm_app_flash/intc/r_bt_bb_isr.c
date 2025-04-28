/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> intc.o -> r_bt_bb_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_bt_bb_isr(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = _DAT_6001108c;
  if ((_DAT_6001108c & 0x40000) != 0) {
    _DAT_60011090 = _DAT_60011090 | 0x40000;
    r_lld_hw_cca_end_isr();
    r_btdm_task_post_from_isr(5);
  }
  if ((uVar1 & 0x80000) != 0) {
    _DAT_60011090 = _DAT_60011090 | 0x80000;
    while ((_DAT_600110d4 & 0x20000000) == 0) {
      uVar4 = _DAT_600110d8 >> 0xf;
      uVar5 = _DAT_600110d8 >> 0x1e;
      uVar2 = _DAT_600110d8 >> 0x18 & 0x3f;
      if (0x27 < uVar2) {
        r_assert_param(uVar2,0,"intc.c",0xad);
      }
      r_lld_hw_cca_isr_eco(uVar4 & 0xff,uVar2,uVar5);
    }
    r_btdm_task_post_from_isr(5);
  }
  if ((uVar1 & 0x400) != 0) {
    _DAT_60011090 = _DAT_60011090 | 0x400;
    iVar3 = r_sdk_config_get_opts_ext();
    if ((*(char *)(iVar3 + 0x11) != '\0') && (iVar3 = r_bt_bb_recorrect_is_dead(), iVar3 != 0)) {
      r_bt_bb_restart_hw_recorrect();
    }
  }
  if ((uVar1 & 0x10000) != 0) {
    _DAT_60011090 = _DAT_60011090 | 0x10000;
    iVar3 = r_sdk_config_get_opts_ext();
    if (*(char *)(iVar3 + 0x11) != '\0') {
      r_bt_bb_restart_hw_recorrect();
    }
  }
  if ((uVar1 & 0x8000) != 0) {
    _DAT_60011090 = _DAT_60011090 | 0x8000;
  }
  if ((uVar1 & 2) != 0) {
    _DAT_60011090 = _DAT_60011090 | 2;
    iVar3 = r_sdk_config_get_opts_ext();
    if (*(char *)(iVar3 + 0x19) == '\x02') {
      r_lld_cca_bb_sync_found_handle();
      return;
    }
  }
  return;
}

