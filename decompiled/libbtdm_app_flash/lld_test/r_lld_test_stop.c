/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> lld_test.o -> r_lld_test_stop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_test_stop(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined2 uVar5;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar4 = _lld_test_env;
  uVar1 = 0xc;
  if (_lld_test_env != 0) {
    iVar2 = r_sdk_config_get_opts_ext();
    if ((*(uint *)(iVar2 + 0x28) & 0x400) != 0) {
      iVar2 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar2 + 0x2c) < 3) {
        r_ble_log_internal_x1
                  (0x400e0002,CONCAT11(*(undefined1 *)(iVar4 + 0x2a),*(undefined1 *)(iVar4 + 0x26)))
        ;
      }
    }
    (*_rwip_rf)(1,_rwip_rf);
    _DAT_60031000 = _DAT_60031000 & 0xffffbfff;
    if (*(char *)(iVar4 + 0x2a) == '\0') {
      r_sch_arb_remove(iVar4,0);
      _DAT_600310d0 = 0;
      puVar3 = (undefined1 *)r_ke_msg_alloc(0x20a,0,0xff,4);
      *puVar3 = 0;
      uVar5 = 0;
      if (*(char *)(iVar4 + 0x26) == '\0') {
        iVar4 = r_emi_get_mem_addr_by_offset(0x400);
        uVar5 = *(undefined2 *)(iVar4 + 0x4a);
      }
      *(undefined2 *)(puVar3 + 2) = uVar5;
      r_ke_msg_send(puVar3);
      r_lld_test_cleanup(0);
    }
    else if (*(char *)(iVar4 + 0x2a) == '\x01') {
      _DAT_60031000 = _DAT_60031000 | 0x4000000;
      *(undefined1 *)(iVar4 + 0x2a) = 2;
    }
    uVar1 = 0;
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar1;
}

