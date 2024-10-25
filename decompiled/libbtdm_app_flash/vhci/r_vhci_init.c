/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> vhci.o -> r_vhci_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_vhci_init(void)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  puVar1 = *(undefined1 **)(_btdm_env_p + 0x24);
  _vhci_env_p = puVar1;
  if (puVar1 == (undefined1 *)0x0) {
    if (0 < _g_bt_plf_log_level) {
      ets_printf("%s %d\n","vhci.c",0x35);
    }
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  *puVar1 = 1;
  uVar2 = (**(code **)(_r_osi_funcs_p + 0x24))(1,1,*(code **)(_r_osi_funcs_p + 0x24));
  *(undefined4 *)(puVar1 + 4) = uVar2;
  return;
}

