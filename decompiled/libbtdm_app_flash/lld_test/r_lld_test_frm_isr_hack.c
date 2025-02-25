/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> lld_test.o -> r_lld_test_frm_isr_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_test_frm_isr_hack(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 uVar5;
  code cVar6;
  undefined2 uVar7;
  
  if (_lld_test_env == 0) {
    r_assert_err(0,"lld_test.c",0x99);
  }
  iVar4 = _lld_test_env;
  iVar2 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar2 + 0x28) & 0x400) != 0) &&
     (iVar2 = r_sdk_config_get_opts_ext(), *(byte *)(iVar2 + 0x2c) < 3)) {
    r_ble_log_internal_x1
              (0x402e0005,
               param_1 << 0x10 |
               (uint)CONCAT11(*(undefined1 *)(iVar4 + 0x26),*(undefined1 *)(iVar4 + 0x2a)));
  }
  iVar2 = _lld_test_env;
  _DAT_600310d0 = 0;
  if ((*(char *)(iVar4 + 0x2a) == '\x02') && (*(char *)(iVar4 + 0x26) == '\x01')) {
    r_sch_arb_remove(iVar4,1);
    puVar3 = (undefined1 *)r_ke_msg_alloc(0x20a,0,0xff,4);
    *puVar3 = 0;
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(puVar3 + 2) = *(undefined2 *)(iVar4 + 0x44);
    r_ke_msg_send(puVar3);
    r_lld_test_cleanup(1);
    return;
  }
  if (_lld_test_env == 0) {
    uVar5 = 0x224;
  }
  else {
    r_sch_arb_remove(_lld_test_env,1);
    bVar1 = DAT_0001101d;
    if (*(char *)(iVar2 + 0x2a) == '\x02') {
      puVar3 = (undefined1 *)r_ke_msg_alloc(0x20a,0,0xff,4);
      *puVar3 = 0;
      uVar7 = 0;
      if (*(char *)(iVar2 + 0x26) == '\0') {
        iVar4 = r_emi_get_mem_addr_by_offset(0x400);
        uVar7 = *(undefined2 *)(iVar4 + 0x4a);
      }
      *(undefined2 *)(puVar3 + 2) = uVar7;
      r_ke_msg_send(puVar3);
      r_lld_test_cleanup(1);
      return;
    }
    cVar6 = r_emi_get_mem_addr_by_offset;
    if (param_1 != 0) {
      cVar6 = (code)(*(char *)(iVar2 + 0x16) + DAT_0001101d);
    }
    *(code *)(iVar2 + 0x16) = cVar6;
    *(ushort *)(iVar2 + 0x14) = bVar1 & 0xf | 0x6000;
    iVar4 = r_sch_arb_insert(iVar2);
    if (iVar4 == 0) {
      *(undefined1 *)(iVar2 + 0x2a) = 0;
      return;
    }
    uVar5 = 0x21e;
  }
  r_assert_err(0,"lld_test.c",uVar5);
  return;
}

