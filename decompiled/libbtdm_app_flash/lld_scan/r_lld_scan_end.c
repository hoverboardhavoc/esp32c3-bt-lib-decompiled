/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_end
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_end(void)

{
  undefined1 uVar1;
  byte bVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = 0;
  while( true ) {
    iVar6 = uVar5 * 4;
    iVar3 = *(int *)(_lld_scan_env + iVar6);
    if (iVar3 != 0) {
      r_ble_log_internal_x2
                (0x40010143,*(undefined4 *)(iVar3 + 0x24),(uint)*(byte *)(iVar3 + 0x3c) << 8 | uVar5
                );
      r_lld_ext_scan_dynamic_pti_process_eco(iVar3,1);
      if (*(char *)(iVar3 + 0x3c) == '\0') {
        r_sch_arb_remove(iVar3,0);
        r_sch_slice_bg_remove(0);
        if (*(char *)(iVar3 + 0x3d) == '\x03') {
          iVar3 = r_sdk_config_get_opts_ext();
          if (*(char *)(iVar3 + 0x18) == '\0') {
            r_assert_err(0,"lld_scan.c",0x4ea);
          }
          r_ble_log_internal_x1(0x40410144,uVar5);
          r_lld_scan_trunc_ind(uVar5);
        }
        r_ke_free(*(undefined4 *)(_lld_scan_env + iVar6));
        iVar3 = _lld_scan_env;
        *(undefined4 *)(iVar6 + _lld_scan_env) = 0;
        *(byte *)(iVar3 + 0xc) = ~(byte)(1 << uVar5) & *(byte *)(iVar3 + 0xc);
      }
      else if (*(char *)(iVar3 + 0x3c) == '\x01') {
        bVar2 = *(byte *)(iVar3 + 0x38);
        iVar6 = r_emi_get_mem_addr_by_offset(0x400);
        *(undefined2 *)((uint)bVar2 * 0x5a + 0x20 + iVar6) = 1;
        _DAT_60031000 = _DAT_60031000 & 0xfeffffff | 0x1000000;
        *(undefined1 *)(iVar3 + 0x3c) = 2;
      }
    }
    if (uVar5 != 0) break;
    uVar5 = 1;
  }
  if (*(char *)(_lld_scan_env + 0xc) == '\0') {
    puVar4 = (undefined1 *)r_ke_msg_alloc(0x206,0,0xff,2);
    uVar1 = *(undefined1 *)(_lld_scan_env + 0xd);
    *puVar4 = 0;
    puVar4[1] = uVar1;
    r_ke_msg_send();
    r_ke_free(_lld_scan_env);
    _lld_scan_env = 0;
  }
  return;
}

