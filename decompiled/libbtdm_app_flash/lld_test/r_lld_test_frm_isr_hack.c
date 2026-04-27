/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_test.o -> r_lld_test_frm_isr_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_test_frm_isr_hack(int param_1)

{
  int iVar1;
  byte bVar2;
  ushort *puVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined4 uVar6;
  code cVar7;
  undefined2 uVar8;
  
  if (_lld_test_env == 0) {
    r_assert_err(0,0x10000,0x99);
  }
  iVar5 = _lld_test_env;
  puVar3 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
  r_ble_log_internal_x1(0x40260164,*puVar3 & 0x1f);
  iVar1 = _lld_test_env;
  _DAT_600310d0 = 0;
  if ((*(char *)(iVar5 + 0x2a) == '\x02') && (*(char *)(iVar5 + 0x26) == '\x01')) {
    r_sch_arb_remove(iVar5,1);
    puVar4 = (undefined1 *)r_ke_msg_alloc(0x20a,0,0xff,4);
    *puVar4 = 0;
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(puVar4 + 2) = *(undefined2 *)(iVar5 + 0x44);
    r_ke_msg_send(puVar4);
    r_lld_test_cleanup(1);
    return;
  }
  if (_lld_test_env == 0) {
    uVar6 = 0x228;
  }
  else {
    r_sch_arb_remove(_lld_test_env,1);
    bVar2 = DAT_00011019;
    if (*(char *)(iVar1 + 0x2a) == '\x02') {
      puVar4 = (undefined1 *)r_ke_msg_alloc(0x20a,0,0xff,4);
      *puVar4 = 0;
      uVar8 = 0;
      if (*(char *)(iVar1 + 0x26) == '\0') {
        iVar5 = r_emi_get_mem_addr_by_offset(0x400);
        uVar8 = *(undefined2 *)(iVar5 + 0x4a);
      }
      *(undefined2 *)(puVar4 + 2) = uVar8;
      r_ke_msg_send(puVar4);
      r_lld_test_cleanup(1);
      return;
    }
    cVar7 = r_emi_get_mem_addr_by_offset;
    if (param_1 != 0) {
      cVar7 = (code)(*(char *)(iVar1 + 0x16) + DAT_00011019);
    }
    *(code *)(iVar1 + 0x16) = cVar7;
    *(ushort *)(iVar1 + 0x14) = bVar2 & 0xf | 0x6000;
    iVar5 = r_sch_arb_insert(iVar1);
    if (iVar5 == 0) {
      *(undefined1 *)(iVar1 + 0x2a) = 0;
      return;
    }
    uVar6 = 0x222;
  }
  r_assert_err(0,0x10000,uVar6);
  return;
}

