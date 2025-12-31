/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> lld_init.o -> r_lld_init_end
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_end(void)

{
  undefined1 uVar1;
  byte bVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = 0;
  while( true ) {
    iVar5 = uVar6 * 4;
    iVar3 = *(int *)(_lld_init_env + iVar5);
    if (iVar3 != 0) {
      r_ble_log_internal_x2
                (0x400200fa,*(undefined4 *)(iVar3 + 0x24),
                 (uint)*(byte *)(iVar3 + 0x31) << 0x18 |
                 (uint)*(byte *)(iVar3 + 0x52) << 8 | (uint)*(byte *)(iVar3 + 0x50) << 0x10 | uVar6)
      ;
      if (*(char *)(iVar3 + 0x31) == '\0') {
        r_sch_arb_remove(iVar3,0);
        r_sch_slice_bg_remove(1);
        r_ke_free(*(undefined4 *)(_lld_init_env + iVar5));
        iVar3 = _lld_init_env;
        *(undefined4 *)(iVar5 + _lld_init_env) = 0;
        *(byte *)(iVar3 + 0x2b) = ~(byte)(1 << uVar6) & *(byte *)(iVar3 + 0x2b);
      }
      else if (*(char *)(iVar3 + 0x31) == '\x01') {
        bVar2 = *(byte *)(iVar3 + 0x52);
        iVar5 = r_emi_get_mem_addr_by_offset(0x400);
        *(undefined2 *)((uint)bVar2 * 0x5a + 0x20 + iVar5) = 1;
        _DAT_60031000 = _DAT_60031000 & 0xfeffffff | 0x1000000;
        *(undefined1 *)(iVar3 + 0x31) = 2;
      }
    }
    if (uVar6 != 0) break;
    uVar6 = 1;
  }
  if (*(char *)(_lld_init_env + 0x2b) == '\0') {
    if (*(int *)(_lld_init_env + 8) == 0) {
      puVar4 = (undefined1 *)r_ke_msg_alloc(0x209,0,0xff,0x38);
      uVar1 = *(undefined1 *)(_lld_init_env + 0x2c);
      puVar4[1] = 0;
      *puVar4 = uVar1;
    }
    r_ke_msg_send();
    r_ke_free(_lld_init_env);
    _lld_init_env = 0;
  }
  return;
}

