/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_end
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_end(void)

{
  bool bVar1;
  undefined1 uVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  uint uVar8;
  
  uVar8 = 0;
  do {
    iVar7 = uVar8 * 4;
    iVar4 = *(int *)(_lld_scan_env + iVar7);
    if (iVar4 != 0) {
      iVar5 = r_sdk_config_get_opts_ext();
      if ((*(uint *)(iVar5 + 0x28) & 8) != 0) {
        iVar5 = r_sdk_config_get_opts_ext();
        if (*(byte *)(iVar5 + 0x2c) < 3) {
          r_ble_log_internal_x2
                    (0x40010002,(uint)*(byte *)(iVar4 + 0x3c) << 8 | uVar8,
                     *(undefined4 *)(iVar4 + 0x24));
        }
      }
      r_lld_ext_scan_dynamic_pti_process_eco(iVar4,1);
      if (*(char *)(iVar4 + 0x3c) == '\0') {
        r_sch_arb_remove(iVar4,0);
        r_sch_slice_bg_remove(0);
        if (*(char *)(iVar4 + 0x3d) == '\x03') {
          iVar4 = r_sdk_config_get_opts_ext();
          if (*(char *)(iVar4 + 0x18) == '\0') {
            r_assert_err(0,"lld_scan.c",0x4aa);
          }
          r_lld_scan_trunc_ind(uVar8);
        }
        r_ke_free(*(undefined4 *)(_lld_scan_env + iVar7));
        iVar4 = _lld_scan_env;
        *(undefined4 *)(iVar7 + _lld_scan_env) = 0;
        *(byte *)(iVar4 + 0xc) = ~(byte)(1 << uVar8) & *(byte *)(iVar4 + 0xc);
      }
      else if (*(char *)(iVar4 + 0x3c) == '\x01') {
        bVar3 = *(byte *)(iVar4 + 0x38);
        iVar7 = r_emi_get_mem_addr_by_offset(0x400);
        *(undefined2 *)((uint)bVar3 * 0x5a + 0x20 + iVar7) = 1;
        _DAT_60031000 = _DAT_60031000 | 0x1000000;
        *(undefined1 *)(iVar4 + 0x3c) = 2;
      }
    }
    bVar1 = uVar8 != 1;
    uVar8 = 1;
  } while (bVar1);
  if (*(char *)(_lld_scan_env + 0xc) == '\0') {
    puVar6 = (undefined1 *)r_ke_msg_alloc(0x206,0,0xff,2);
    uVar2 = *(undefined1 *)(_lld_scan_env + 0xd);
    *puVar6 = 0;
    puVar6[1] = uVar2;
    r_ke_msg_send();
    r_ke_free(_lld_scan_env);
    _lld_scan_env = 0;
  }
  return;
}

