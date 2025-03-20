/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> lld_test.o -> r_lld_test_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_test_frm_cbk(undefined4 param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  int iVar6;
  code cVar7;
  undefined2 uVar8;
  
  if (param_2 == 1) {
    iVar6 = 1;
  }
  else {
    if (param_2 != 0) {
      if (param_2 != 2) {
        r_assert_param(param_1,"lld_test.c",0x241);
        return;
      }
      if (_lld_test_env != 0) {
        uVar5 = 2;
        while (iVar6 = r_lld_rxdesc_check_hack(0,uVar5), iVar6 != 0) {
          uVar5 = r_lld_rxdesc_free();
        }
        return;
      }
      r_assert_err(0,"lld_test.c",0x1e8);
      return;
    }
    iVar6 = 0;
  }
  if (_lld_test_env == 0) {
    r_assert_err(0,"lld_test.c",0x99);
  }
  iVar1 = _lld_test_env;
  iVar3 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar3 + 0x28) & 0x400) != 0) &&
     (iVar3 = r_sdk_config_get_opts_ext(), *(byte *)(iVar3 + 0x2c) < 3)) {
    r_ble_log_internal_x1
              (0x402e0005,
               iVar6 << 0x10 |
               (uint)CONCAT11(*(undefined1 *)(iVar1 + 0x26),*(undefined1 *)(iVar1 + 0x2a)));
  }
  iVar3 = _lld_test_env;
  _DAT_600310d0 = 0;
  if ((*(char *)(iVar1 + 0x2a) == '\x02') && (*(char *)(iVar1 + 0x26) == '\x01')) {
    r_sch_arb_remove(iVar1,1);
    puVar4 = (undefined1 *)r_ke_msg_alloc(0x20a,0,0xff,4);
    *puVar4 = 0;
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(puVar4 + 2) = *(undefined2 *)(iVar6 + 0x44);
    r_ke_msg_send(puVar4);
    r_lld_test_cleanup(1);
    return;
  }
  if (_lld_test_env == 0) {
    uVar5 = 0x224;
  }
  else {
    r_sch_arb_remove(_lld_test_env,1);
    bVar2 = DAT_0001101d;
    if (*(char *)(iVar3 + 0x2a) == '\x02') {
      puVar4 = (undefined1 *)r_ke_msg_alloc(0x20a,0,0xff,4);
      *puVar4 = 0;
      uVar8 = 0;
      if (*(char *)(iVar3 + 0x26) == '\0') {
        iVar6 = r_emi_get_mem_addr_by_offset(0x400);
        uVar8 = *(undefined2 *)(iVar6 + 0x4a);
      }
      *(undefined2 *)(puVar4 + 2) = uVar8;
      r_ke_msg_send(puVar4);
      r_lld_test_cleanup(1);
      return;
    }
    cVar7 = r_emi_get_mem_addr_by_offset;
    if (iVar6 != 0) {
      cVar7 = (code)(*(char *)(iVar3 + 0x16) + DAT_0001101d);
    }
    *(code *)(iVar3 + 0x16) = cVar7;
    *(ushort *)(iVar3 + 0x14) = bVar2 & 0xf | 0x6000;
    iVar6 = r_sch_arb_insert(iVar3);
    if (iVar6 == 0) {
      *(undefined1 *)(iVar3 + 0x2a) = 0;
      return;
    }
    uVar5 = 0x21e;
  }
  r_assert_err(0,"lld_test.c",uVar5);
  return;
}

