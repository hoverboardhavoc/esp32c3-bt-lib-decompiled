/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_test.o -> r_lld_test_stop_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_lld_test_stop_hack(void)

{
  undefined1 *puVar1;
  int iVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar2 = _lld_test_env;
  uVar4 = 0xc;
  if (_lld_test_env != 0) {
    r_ble_log_internal_x1
              (0x40060165,
               CONCAT11(*(undefined1 *)(_lld_test_env + 0x2a),*(undefined1 *)(_lld_test_env + 0x26))
              );
    (*_r_emi_get_mem_addr_by_offset)(1,_r_emi_get_mem_addr_by_offset);
    _DAT_60031000 = _DAT_60031000 & 0xffffbfff;
    if (*(char *)(iVar2 + 0x2a) == '\0') {
      r_sch_arb_remove(iVar2,0);
      _DAT_600310d0 = 0;
      puVar1 = (undefined1 *)r_ke_msg_alloc(0x20a,0,0xff,4);
      *puVar1 = 0;
      uVar3 = 0;
      if (*(char *)(iVar2 + 0x26) == '\0') {
        iVar2 = r_emi_get_mem_addr_by_offset(0x400);
        uVar3 = *(undefined2 *)(iVar2 + 0x4a);
      }
      *(undefined2 *)(puVar1 + 2) = uVar3;
      r_ke_msg_send(puVar1);
      r_lld_test_cleanup(0);
      uVar4 = 0;
    }
    else {
      if (*(char *)(iVar2 + 0x2a) == '\x01') {
        _DAT_60031000 = _DAT_60031000 | 0x4000000;
        *(undefined1 *)(iVar2 + 0x2a) = 2;
      }
      uVar4 = 0;
    }
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar4;
}

