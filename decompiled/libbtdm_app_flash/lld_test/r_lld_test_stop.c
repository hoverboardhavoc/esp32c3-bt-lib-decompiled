/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_test.o -> r_lld_test_stop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_lld_test_stop(void)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined2 uVar4;
  undefined1 uVar5;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar3 = _lld_test_env;
  uVar5 = 0xc;
  if (_lld_test_env != 0) {
    iVar1 = r_sdk_config_get_opts_ext();
    if ((*(uint *)(iVar1 + 0x28) & 0x400) != 0) {
      iVar1 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar1 + 0x2c) < 3) {
        r_ble_log_internal_x1
                  (0x400e0002,CONCAT11(*(undefined1 *)(iVar3 + 0x2a),*(undefined1 *)(iVar3 + 0x26)))
        ;
      }
    }
    (*_r_emi_get_mem_addr_by_offset)(1,_r_emi_get_mem_addr_by_offset);
    _DAT_60031000 = _DAT_60031000 & 0xffffbfff;
    if (*(char *)(iVar3 + 0x2a) == '\0') {
      r_sch_arb_remove(iVar3,0);
      _DAT_600310d0 = 0;
      puVar2 = (undefined1 *)r_ke_msg_alloc(0x20a,0,0xff,4);
      *puVar2 = 0;
      uVar4 = 0;
      if (*(char *)(iVar3 + 0x26) == '\0') {
        iVar3 = r_emi_get_mem_addr_by_offset(0x400);
        uVar4 = *(undefined2 *)(iVar3 + 0x4a);
      }
      *(undefined2 *)(puVar2 + 2) = uVar4;
      r_ke_msg_send(puVar2);
      r_lld_test_cleanup(0);
      uVar5 = 0;
    }
    else {
      if (*(char *)(iVar3 + 0x2a) == '\x01') {
        _DAT_60031000 = _DAT_60031000 | 0x4000000;
        *(undefined1 *)(iVar3 + 0x2a) = 2;
      }
      uVar5 = 0;
    }
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar5;
}

