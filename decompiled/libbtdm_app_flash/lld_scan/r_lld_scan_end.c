/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
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
  int iVar5;
  int iVar6;
  
  iVar6 = 0;
  while( true ) {
    iVar5 = iVar6 * 4;
    iVar3 = *(int *)(_lld_scan_env + iVar5);
    if (iVar3 != 0) {
      r_lld_ext_scan_dynamic_pti_process_eco(iVar3,1);
      if (*(char *)(iVar3 + 0x3c) == '\0') {
        r_sch_arb_remove(iVar3,0);
        r_sch_slice_bg_remove(0);
        if (*(char *)(iVar3 + 0x3d) == '\x03') {
          iVar3 = r_sdk_config_get_opts_ext();
          if (*(char *)(iVar3 + 0x18) == '\0') {
            r_assert_err(0,"lld_scan.c",0x492);
          }
          r_lld_scan_trunc_ind(iVar6);
        }
        r_ke_free(*(undefined4 *)(_lld_scan_env + iVar5));
        iVar3 = _lld_scan_env;
        *(undefined4 *)(iVar5 + _lld_scan_env) = 0;
        *(byte *)(iVar3 + 0xc) = ~(byte)(1 << iVar6) & *(byte *)(iVar3 + 0xc);
      }
      else if (*(char *)(iVar3 + 0x3c) == '\x01') {
        bVar2 = *(byte *)(iVar3 + 0x38);
        iVar5 = r_emi_get_mem_addr_by_offset(0x400);
        *(undefined2 *)(iVar5 + (uint)bVar2 * 0x5a + 0x20) = 1;
        _DAT_60031000 = _DAT_60031000 & 0xfeffffff | 0x1000000;
        *(undefined1 *)(iVar3 + 0x3c) = 2;
      }
    }
    if (iVar6 != 0) break;
    iVar6 = 1;
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

