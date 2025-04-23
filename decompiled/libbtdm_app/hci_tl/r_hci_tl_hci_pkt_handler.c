/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> hci_tl.o -> r_hci_tl_hci_pkt_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_hci_tl_hci_pkt_handler(void)

{
  char *pcVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  void *__dest;
  undefined2 uVar5;
  code *pcVar6;
  
  pcVar1 = _DAT_00012030;
  if (*_DAT_00012030 == '\x01') {
    uVar3 = 6;
    if (_DAT_00012030[3] != '\0') {
      uVar3 = 7;
    }
                    /* WARNING: Could not recover jumptable at 0x00010cfa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_modules_funcs_p + 0x108))(uVar3,*(code **)(_r_modules_funcs_p + 0x108));
    return;
  }
  if (*_DAT_00012030 == '\x02') {
    uVar2 = *(undefined2 *)(_DAT_00012030 + 1);
    if (*(short *)(_DAT_00012030 + 3) == 0) {
      pcVar6 = (code *)_r_ip_funcs_p[1];
      iVar4 = 0;
      uVar5 = 0;
    }
    else {
      iVar4 = (*(code *)*_r_ip_funcs_p)(uVar2,(code *)*_r_ip_funcs_p);
      if ((iVar4 == 0) ||
         (__dest = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))(*(code **)(_r_plf_funcs_p + 0xbc)),
         __dest == (void *)0x0)) {
        if (1 < _g_bt_plf_log_level) {
          ets_printf("HCITL: fail to alloc acl %0x, %0x\n",iVar4,0);
        }
        goto _L166;
      }
      memcpy(__dest,pcVar1 + 5,(uint)*(ushort *)(pcVar1 + 3));
      uVar5 = *(undefined2 *)(pcVar1 + 3);
      uVar2 = *(undefined2 *)(pcVar1 + 1);
      pcVar6 = (code *)_r_ip_funcs_p[1];
    }
    (*pcVar6)(uVar2,uVar5,iVar4,pcVar6);
  }
_L166:
                    /* WARNING: Could not recover jumptable at 0x00010d86. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 0xdc))(*(code **)(_r_plf_funcs_p + 0xdc));
  return;
}

