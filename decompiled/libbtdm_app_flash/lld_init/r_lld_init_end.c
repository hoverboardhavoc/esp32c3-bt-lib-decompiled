/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
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
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  uint uVar7;
  
  uVar7 = 0;
  while( true ) {
    iVar6 = uVar7 * 4;
    iVar3 = *(int *)(_lld_init_env + iVar6);
    if (iVar3 != 0) {
      iVar4 = r_sdk_config_get_opts_ext();
      if ((*(uint *)(iVar4 + 0x28) & 0x10) != 0) {
        iVar4 = r_sdk_config_get_opts_ext();
        if (*(byte *)(iVar4 + 0x2c) < 3) {
          r_ble_log_internal_x2
                    (0x400f0002,
                     (uint)*(byte *)(iVar3 + 0x52) << 8 |
                     (uint)*(byte *)(iVar3 + 0x31) << 0x18 | (uint)*(byte *)(iVar3 + 0x50) << 0x10 |
                     uVar7,*(undefined4 *)(iVar3 + 0x24));
        }
      }
      if (*(char *)(iVar3 + 0x31) == '\0') {
        r_sch_arb_remove(iVar3,0);
        r_sch_slice_bg_remove(1);
        r_ke_free(*(undefined4 *)(_lld_init_env + iVar6));
        iVar3 = _lld_init_env;
        *(undefined4 *)(iVar6 + _lld_init_env) = 0;
        *(byte *)(iVar3 + 0x2b) = ~(byte)(1 << uVar7) & *(byte *)(iVar3 + 0x2b);
      }
      else if (*(char *)(iVar3 + 0x31) == '\x01') {
        bVar2 = *(byte *)(iVar3 + 0x52);
        iVar6 = r_emi_get_mem_addr_by_offset(0x400);
        *(undefined2 *)(iVar6 + (uint)bVar2 * 0x5a + 0x20) = 1;
        _DAT_60031000 = _DAT_60031000 & 0xfeffffff | 0x1000000;
        *(undefined1 *)(iVar3 + 0x31) = 2;
      }
    }
    if (uVar7 != 0) break;
    uVar7 = 1;
  }
  if (*(char *)(_lld_init_env + 0x2b) == '\0') {
    if (*(int *)(_lld_init_env + 8) == 0) {
      puVar5 = (undefined1 *)r_ke_msg_alloc(0x209,0,0xff,0x38);
      uVar1 = *(undefined1 *)(_lld_init_env + 0x2c);
      puVar5[1] = 0;
      *puVar5 = uVar1;
    }
    r_ke_msg_send();
    r_ke_free(_lld_init_env);
    _lld_init_env = 0;
  }
  return;
}

