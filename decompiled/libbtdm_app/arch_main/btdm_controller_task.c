/*
 * Last changed at upstream commit 90b025633add12d18ab056ce8db20d06deb40f06
 * https://github.com/espressif/esp32c3-bt-lib/commit/90b025633add12d18ab056ce8db20d06deb40f06
 * Upstream date: 2021-04-28 17:58:45 +0800
 * Upstream subject: Update ESP32C3/ESP32S3 bt-lib(501d88d7)
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
  undefined4 uVar2;
  int iVar3;
  char cStack_38;
  undefined1 uStack_37;
  undefined1 *puStack_34;
  
  uVar2 = 0;
  do {
    iVar3 = (**(code **)(_r_osi_funcs_p + 0x34))
                      (_g_rw_schd_sem,0xffffffff,*(code **)(_r_osi_funcs_p + 0x34));
    if (iVar3 == 0) {
      return;
    }
    bVar1 = false;
    while (iVar3 = (**(code **)(_r_osi_funcs_p + 0x5c))
                             (_g_rw_schd_queue,&cStack_38,0,*(code **)(_r_osi_funcs_p + 0x5c)),
          iVar3 == 1) {
      switch(cStack_38) {
      case '\x02':
        (**(code **)(_r_ip_funcs_p + 0x4c))(*(code **)(_r_ip_funcs_p + 0x4c));
        break;
      case '\a':
      case '\b':
      case '\t':
      case '\n':
        if (cStack_38 == '\t') {
          uVar2 = 2;
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
              uVar2 = 0;
              (**(code **)(_r_osi_funcs_p + 0x38))(_g_rw_init_sem,*(code **)(_r_osi_funcs_p + 0x38))
              ;
              break;
            }
            rw_pre_main();
          }
          uVar2 = 1;
          (**(code **)(_r_osi_funcs_p + 0x38))(_g_rw_init_sem,*(code **)(_r_osi_funcs_p + 0x38));
        }
        break;
      case '\v':
        ble_txpwr_set_inter(*puStack_34,puStack_34[1]);
        break;
      case '\r':
        btdm_vnd_offload_process(uStack_37,puStack_34);
      }
      bVar1 = true;
      (**(code **)(_r_plf_funcs_p + 0x30))(&cStack_38,*(code **)(_r_plf_funcs_p + 0x30));
      btdm_rw_run(uVar2);
    }
    if (!bVar1) {
      btdm_rw_run(uVar2);
    }
  } while( true );
}

