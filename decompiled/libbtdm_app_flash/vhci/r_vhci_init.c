/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> vhci.o -> r_vhci_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_vhci_init(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  iVar1 = _r_osi_funcs_p;
  puVar2 = *(undefined1 **)(_btdm_env_p + 0x24);
  _vhci_env_p = puVar2;
  if (puVar2 == (undefined1 *)0x0) {
    if (0 < _g_bt_plf_log_level) {
      ets_printf("%s %d\n",0x10000,0x35);
    }
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  *puVar2 = 1;
  uVar3 = (**(code **)(iVar1 + 0x24))(1,*(code **)(iVar1 + 0x24));
  *(undefined4 *)(puVar2 + 4) = uVar3;
  return;
}

