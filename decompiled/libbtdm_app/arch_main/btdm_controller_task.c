/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void btdm_controller_task(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  char cStack_38;
  undefined1 uStack_37;
  undefined1 *puStack_34;
  
  uVar3 = 0;
  do {
    pcVar4 = *(code **)(_r_osi_funcs_p + 0x34);
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xf8))(*(code **)(_r_plf_funcs_p + 0xf8));
    iVar2 = (*pcVar4)(*(undefined4 *)(iVar2 + 4),0xffffffff);
    if (iVar2 == 0) {
      return;
    }
    bVar1 = false;
    while (iVar2 = (**(code **)(_r_osi_funcs_p + 0x5c))
                             (_g_rw_schd_queue,&cStack_38,0,*(code **)(_r_osi_funcs_p + 0x5c)),
          iVar2 == 1) {
      switch(cStack_38) {
      case '\x02':
        (**(code **)(_r_ip_funcs_p + 0x4c))(*(code **)(_r_ip_funcs_p + 0x4c));
        break;
      case '\a':
      case '\b':
      case '\t':
      case '\n':
        if (cStack_38 == '\t') {
          uVar3 = 2;
          (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
          (**(code **)(_r_modules_funcs_p + 0x1b8))(*(code **)(_r_modules_funcs_p + 0x1b8));
          btdm_controller_on_reset();
          r_intc_enable();
          (**(code **)(_r_osi_funcs_p + 0x38))(_g_rw_init_sem,*(code **)(_r_osi_funcs_p + 0x38));
        }
        else {
          if (cStack_38 == '\n') {
            (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
            r_intc_disable();
            btdm_controller_on_reset();
            (**(code **)(_r_ip_funcs_p + 0x124))(2,*(code **)(_r_ip_funcs_p + 0x124));
          }
          else {
            if (cStack_38 == '\b') {
              rw_stop();
              uVar3 = 0;
              (**(code **)(_r_osi_funcs_p + 0x38))(_g_rw_init_sem,*(code **)(_r_osi_funcs_p + 0x38))
              ;
              break;
            }
            rw_pre_main();
          }
          uVar3 = 1;
          (**(code **)(_r_osi_funcs_p + 0x38))(_g_rw_init_sem,*(code **)(_r_osi_funcs_p + 0x38));
        }
        break;
      case '\v':
        ble_txpwr_set_inter(*puStack_34,puStack_34[1]);
        break;
      case '\r':
        (**(code **)(_r_plf_funcs_p + 0x114))
                  (uStack_37,puStack_34,*(code **)(_r_plf_funcs_p + 0x114));
      }
      bVar1 = true;
      (**(code **)(_r_plf_funcs_p + 0x30))(&cStack_38,*(code **)(_r_plf_funcs_p + 0x30));
      btdm_rw_run(uVar3);
    }
    if (!bVar1) {
      btdm_rw_run(uVar3);
    }
  } while( true );
}

